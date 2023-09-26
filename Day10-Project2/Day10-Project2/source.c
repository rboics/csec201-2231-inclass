#include <stdio.h>
#include "stack.h"





int main(void) {
	struct stack myStack;
	initializeStack(&myStack);
	push(&myStack, 10);
	push(&myStack, 20);
	push(&myStack, 30);
	print(&myStack);
	int popped = pop(&myStack);
	printf("Popped: %d\n", popped);
	print(&myStack);
}