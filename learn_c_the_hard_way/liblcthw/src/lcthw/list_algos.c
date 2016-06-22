#include "list_algos.h"

int List_bubble_sort(List *list, List_compare *cmp) {
    ListNode* last = NULL;
    while (list->first != last) {
    	ListNode* cur = list->first;
    	while (cur->next != last) {
    		if (cmp(cur->value, cur->next->value) > 0) {
                List_swap_forward(list, cur);
    		}
    		cur = cur->next;
    	}
        last = cur;
    }

	return 0;
}

List *List_merge_sort(List *list, List_compare *cmp) {
    if (list->count == 1) {
        List *res = List_create();
        List_push(res, list->first->value);
        return res;
    }

    int middle = list->count / 2;
    List *l= List_sublist(list, 0, middle);
    List *r= List_sublist(list, middle, list->count - middle);

    List *left = List_merge_sort(l, cmp);
    List *right = List_merge_sort(r, cmp);
    List_destroy(l);
    List_destroy(r);

    ListNode* leftNode = left->first;
    ListNode* rightNode = right->first;

    List *res = List_create();
    while (leftNode != NULL || rightNode != NULL) {
        if (leftNode == NULL) {
            List_push(res, rightNode->value);
            rightNode = rightNode->next;
        } else if (rightNode == NULL) {
            List_push(res, leftNode->value);
            leftNode = leftNode->next;
        } else if (cmp(leftNode->value, rightNode->value) < 0) {
            List_push(res, leftNode->value);
            leftNode = leftNode->next;
        } else {
            List_push(res, rightNode->value);
            rightNode = rightNode->next;
        }
    }

    List_destroy(left);
    List_destroy(right);

	return res;
}
