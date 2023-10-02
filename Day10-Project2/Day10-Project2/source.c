#include <stdio.h>
#include "stack.h"
#include "queue.h"





int main(void) {
	struct queue myqueue;
	initializeQueue(&myqueue);
	enqueue(&myqueue, 10);
	enqueue(&myqueue, 20);
	enqueue(&myqueue, 30);
	printQ(&myqueue);
	int popped = dequeue(&myqueue);
	printf("Popped: %d\n", popped);
	printQ(&myqueue);
}