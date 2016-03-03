#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message) {
	if (errno) {
		perror(message);
	} else {
		printf("Error: %s\n", message);
	}
	exit(1);
}

typedef int (*compare_cb)(int a, int b);
typedef int* (*sort)(int *numbers, int count, compare_cb cmp);

int *bubble_sort(int *numbers, int count, compare_cb cmp) {
	int temp = 0;;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if (!target) die("Memory error.");

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++) {
		for (j = 0; j < count - 1; j++) {
			if (cmp(target[j], target[j+1]) > 0) {
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

void merge_sort(int *numbers, int count, compare_cb cmp, int *target) {
	if (count == 1) {
		target[0] = numbers[0];
		return;
	}

	int middle = count / 2;
	merge_sort(numbers, middle, cmp, target);
	merge_sort(&numbers[middle], count - middle, cmp, &target[middle]);
	memcpy(numbers, target, sizeof(int) * count);
	int i = 0;
	int lIdx = 0;
	int rIdx = middle;
	for (i = 0; i < count; i++) {
		if (lIdx == middle) {
			target[i] = numbers[rIdx++];
		} else if (rIdx == count) {
			target[i] = numbers[lIdx++];
		} else if (cmp(numbers[lIdx], numbers[rIdx]) > 0) {
			target[i] = numbers[rIdx++];
		} else {
			target[i] = numbers[lIdx++];
		}
	}
}

int *merge_sort_wrapper(int *numbers, int count, compare_cb cmp) {
	int *sorted = malloc(count * sizeof(int));
	merge_sort(numbers, count, cmp, sorted);
	return sorted;
}

int sorted_order(int a, int b) {
	return a - b;
}

int reverse_order(int a, int b) {
	return b - a;
}

int strange_order(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

void test_sorting(int *numbers, int count, sort sort, compare_cb cmp) {
	int i = 0;
	int *sorted = sort(numbers, count, cmp);
	if (!sorted) die("Failed to sort as requested.");
	merge_sort(numbers, count, cmp, sorted);

	for (i = 0; i < count; i++) {
		// printf("%d ", sorted[i]);
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted);
}

int main(int argc, char const *argv[]) {
	if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if (!numbers) die("Memory error");

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}	

	test_sorting(numbers, count, merge_sort_wrapper, sorted_order);
	test_sorting(numbers, count, bubble_sort, sorted_order);
	test_sorting(numbers, count, merge_sort_wrapper, reverse_order);
	test_sorting(numbers, count, bubble_sort, reverse_order);
	test_sorting(numbers, count, merge_sort_wrapper, strange_order);
	test_sorting(numbers, count, bubble_sort, strange_order);

	free(numbers);

	return 0;
}