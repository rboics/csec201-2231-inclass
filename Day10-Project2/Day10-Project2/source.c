#include <stdio.h>
#include "stack.h"
#include "queue.h"





int main(void) {
	struct queue myqueue;
	printf("myqueue addr: %p\n", &myqueue);
	initializeQueue(&myqueue);
	enqueue(&myqueue, 1);
	enqueue(&myqueue, 2);
	enqueue(&myqueue, 3);
	printQ(&myqueue);
	int popped = dequeue(&myqueue);
	printf("Popped: %d\n", popped);
	printQ(&myqueue);
	int result = compareQueues(&myqueue, &myqueue);
	printf("result: %d\n", result);
}