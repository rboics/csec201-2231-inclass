//This would be used for functions related to Stack

#include "stack.h" //"" indicate that this is a local file

void initializeStack(struct stack* s) {
	//(*s).size = 0;	// .size if the left side of the . is an instance
	s->size = 0;    // ->size if the left side of the . is a pointer
	s->top = NULL;  //Make the top of the stack point at nothing
}

void push(struct stack* s, int data) {
	//We'll allocate one element's worth of bytes on the heap
	struct element* newElement = malloc(sizeof(struct element));
	newElement->data = data; //Set data portion
	newElement->next = s->top;
	s->top = newElement;
	s->size++;
}

int pop(struct stack* s) {
	//Should return the value at the top
	//	if empty, return 0
	//And should delete the value at the top --> free()
	//NULL == '\0'? yes
	if (s->top == NULL) return 0;
	struct element* temp = s->top;
	int tempData = temp->data;
	s->top = temp->next; //Making the stack point one element down
	free(temp);
	s->size--;
	return tempData;
}

void print(struct stack* s) {
	struct element* temp = s->top;
	printf("Stack contents: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}






