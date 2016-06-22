#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";

char *test_create() {
	list = List_create();
	mu_assert(list != NULL, "Failed to create list.");

	return NULL;
}

char *test_destroy() {
	List_clear_destroy(list);
	return NULL;
}

char *test_push_pop() {
	List_push(list, test1);
	mu_assert(List_last(list) == test1, "Wrong last value.");

	List_push(list, test2);
	mu_assert(List_last(list) == test2, "Wrong last value.");

	List_push(list, test3);
	mu_assert(List_last(list) == test3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	char *val = List_pop(list);
	mu_assert(val == test3, "Wrong value on pop");

	val = List_pop(list);
	mu_assert(val == test2, "Wrong value on pop");

	val = List_pop(list);
	mu_assert(val == test1, "Wrong value on pop");
	mu_assert(List_count(list) == 0, "Wrong count after pop.");

	return NULL;
}

char *test_unshift() {
	List_unshift(list, test1);
	mu_assert(List_first(list) == test1, "Wrong first value.");

	List_unshift(list, test2);
	mu_assert(List_first(list) == test2, "Wrong first value.");

	List_unshift(list, test3);
	mu_assert(List_first(list) == test3, "Wrong first value.");
	mu_assert(List_count(list) == 3, "Wrong count on unshift.");

	return NULL;
}

char *test_remove() {
	char *val = List_remove(list, list->first->next);
	mu_assert(val == test2, "Wrong remove element.");
	mu_assert(List_count(list) == 2, "Wrong count after remove.");
	mu_assert(List_first(list) == test3, "Wrong first after remove.");
	mu_assert(List_last(list) == test1, "Wrong last after remvove.");

	return NULL;
}

char *test_shift() {
	mu_assert(List_count(list) != 0, "Wrong count before shift.");

	char* val = List_shift(list);
	mu_assert(val == test3, "Wrong value on shift.");

	val = List_shift(list);
	mu_assert(val == test1, "Wrong value on shift.");
	mu_assert(List_count(list) == 0, "Wrong count after shift. ");

	return NULL;
}

int int_cmp(void *a, void *b) {
	return *((int*) a) - *((int*) b);
}

char *test_index_of() {
	while (List_count(list) > 0) {
		ListNode* node = List_shift(list);
		free(node);
	}
	mu_assert(List_count(list) == 0, "Wrong count before index of.");

    int* i0 = malloc(sizeof(int));
    *i0 = 0;
    int* i1 = malloc(sizeof(int));
    *i1 = 1;
    int* i2 = malloc(sizeof(int));
    *i2 = -10;
    int* i3 = malloc(sizeof(int));
    *i3 = 1000;
    int* i4 = malloc(sizeof(int));
    *i4 = 1001;

	List_push(list, i1);
	mu_assert(List_last(list) == i1, "Wrong last value.");

	List_push(list, i2);
	mu_assert(List_last(list) == i2, "Wrong last value.");

	List_push(list, i3);
	mu_assert(List_last(list) == i3, "Wrong last value.");
	mu_assert(List_count(list) == 3, "Wrong count on push.");

	int idx = List_index_of(list, i0, &int_cmp);
	mu_assert(idx == -1, "Wrong index of 0 value");
	idx = List_index_of(list, i1, &int_cmp);
	mu_assert(idx == 0, "Wrong index of 1 value");
	idx = List_index_of(list, i2, &int_cmp);
	mu_assert(idx == 1, "Wrong index of -10 value");
	idx = List_index_of(list, i3, &int_cmp);
	mu_assert(idx == 2, "Wrong index of 1000 value");
	idx = List_index_of(list, i4, &int_cmp);
	mu_assert(idx == -1, "Wrong index of 1001 value");

	free(i0);
	free(i4);
	return NULL;
}

char *test_swap_forward() {
	List *list2 = List_create();
	List_push(list2, test1);
	List_push(list2, test2);
	List_push(list2, test3);

	List_swap_forward(list2, list2->first);
	mu_assert(List_first(list2) == test2, "Wrong first value.");
	mu_assert(list2->first->next->value == test1, "Wrong second value.");
	mu_assert(list2->first->next->next->value == test3, "Wrong last value.");

	List_swap_forward(list2, list2->first->next);
	mu_assert(List_first(list2) == test2, "Wrong first value.");
	mu_assert(list2->first->next->value == test3, "Wrong second value.");
	mu_assert(list2->first->next->next->value == test1, "Wrong third value.");

	List_destroy(list2);

	return NULL;
}

char *test_sublist() {
    List *list3 = List_create();
    List_push(list3, test1);
    List_push(list3, test2);
    List_push(list3, test3);

    List *sublist = List_sublist(list3, 1, 2);
    mu_assert(sublist->first->value == list3->first->next->value, "Wrong first node");
    mu_assert(sublist->last->value == list3->last->value, "Wrong last node");

    List_destroy(list3);
    free(sublist);

    return NULL;
}

char *all_tests() {
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	mu_run_test(test_unshift);
	mu_run_test(test_remove);
	mu_run_test(test_shift);
	mu_run_test(test_index_of);
	mu_run_test(test_swap_forward);
	mu_run_test(test_sublist);
	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);
