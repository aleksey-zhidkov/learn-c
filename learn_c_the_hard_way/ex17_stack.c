#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int value;
	struct Stack* tail;
} Stack;

Stack NIL = {.value = 0, .tail = NULL};

Stack* new_stack() {
	return &NIL;
}

Stack* push(Stack *stack, int value) {
	Stack* new_stack = malloc(sizeof(Stack));
	new_stack->value = value;
	new_stack->tail = stack;
	return new_stack;
}

int peek(Stack *stack) {
	return stack->value;
}

Stack* pop(Stack *stack) {
	Stack* res = stack->tail;
	free(stack);
	return res;
}

int main(int argc, char const *argv[]) {
	Stack* stack = new_stack();
	stack = push(stack, 1);
	stack = push(stack, 2);
	stack = push(stack, 3);
	int i;
	for (i = 0; i < 3; i++) {
		printf("%d\n", peek(stack));
		stack = pop(stack);
	}
	return 0;
}