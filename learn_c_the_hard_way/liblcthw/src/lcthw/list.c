#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create() {
    return calloc(1, sizeof(List));
}

int List_destroy(List *list) {
	check(list, "List can't be NULL.");
    LIST_FOREACH(list, first, next, cur) {
    	if (cur->prev) {
    		free(cur->prev);
    	}
    }
    free(list->last);
    free(list);
error:
	return -1;
}

void List_clear(List *list) {
	LIST_FOREACH(list, first, next, cur) {
		free(cur->value);
	}
}

void List_clear_destroy(List *list) {
    LIST_FOREACH(list, first, next, cur) {
    	if (cur->prev) {
    		free(cur->prev);
    	}
		free(cur->value);
    }
    free(list->last);
    free(list);
}

void List_push(List *list, void *value) {
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

	list->count++;

error:
	return;
}

void *List_pop(List *list) {
	ListNode *node = list->last;
	return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value) {
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);

	node->value = value;

	if (list->first == NULL) {
		list->first = node;
		list->last = node;
	} else {
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}

	list->count++;

error:
	return;
}

void *List_shift(List *list) {
	ListNode *node = list->first;
	return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node) {
	void *result = NULL;

	check(list->first && list->last, "List is empty.");
	check(node, "Node can't be NULL.");

	if (node == list->first && node == list->last) {
		list->first = NULL;
		list->last = NULL;
	} else if (node == list->first) {
		list->first = node->next;
		check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
		list->first->prev = NULL;
	} else if (node == list->last) {
		list->last = node->prev;
		check(list->last != NULL, "Invalid list, somehow got a last that is NULL.");
		list->last->next = NULL;
	} else {
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next = after;
	}

	list->count--;
	result = node->value;
	free(node);

error:
	return result;
}

int List_swap_forward(List *list, ListNode* node) {
	check(node, "Node can't be NULL");
	if (node->next == NULL) {
		return -1;
	}

	void* tmp = node->next->value;
	node->next->value = node->value;
	node->value = tmp;
	
	return 1;
error:
	return -1;
}

int List_index_of(List *list, void *e, List_compare cmp) {
	int idx = 0;
    LIST_FOREACH(list, first, next, cur) {
    	if (cmp(&cur->value, &e) == 0) {
    		return idx;
    	}
    	idx++;
    }
    return -1;
}

List *List_sublist(List *list, int from, int size) {
	check(from + size <= list->count, "from + size (%d+%d) greater than list size %d", from, size, list->count);

	int i;
	ListNode *fromNode = list->first;
	for (i = 0; i < from; i++) {
		fromNode = fromNode->next;
	}
	List *sublist = List_create();
	for (i = 0; i < size; i++) {
		List_push(sublist, fromNode->value);
		fromNode = fromNode->next;
	}

	return sublist;
error:
    return NULL;
}