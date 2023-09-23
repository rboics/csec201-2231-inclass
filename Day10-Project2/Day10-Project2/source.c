#include <stdio.h>

struct element {
	int* data;
	struct element* next;
};

struct stack {
	int size;
	struct element* top;
};

void initializeStack(struct stack* s) {
	//(*s).size = 0;	// .size if the left side of the . is an instance
	s->size = 0;    // ->size if the left side of the . is a pointer
	s->top = NULL;  //Make the top of the stack point at nothing
}

void push(struct stack* s, int data) {
	//We'll allocate one element's worth of bytes on the heap
	struct element* newElement = malloc(sizeof(struct element));

}


int main(void) {

}