//This would be used for functions related to queue

#include "queue.h" //"" indicate that this is a local file

void initializeQueue(struct queue* s) {
	//(*s).size = 0;	// .size if the left side of the . is an instance
	s->size = 0;    // ->size if the left side of the . is a pointer
	s->top = NULL;  //Make the top of the queue point at nothing
}

void enqueue(struct queue* s, int data) {
	//We'll allocate one element's worth of bytes on the heap
	struct element* newElement = malloc(sizeof(struct element));
	newElement->data = data; //Set data portion
	newElement->next = s->top;
	s->top = newElement;
	s->size++;
}

int dequeue(struct queue* s) {
	//Should return the value at the top
	//	if empty, return 0
	//And should delete the value at the top --> free()
	//NULL == '\0'? yes
	// 
	//Is queue empty?
	if (s->top == NULL) return 0;
	else if (s->top->next == NULL) {

		//Is the queue of length 1?
		struct element* temp = s->top;
		int tempData = temp->data;
		s->top = temp->next; //Making the queue point one element down
		free(temp);
		s->size--;
		return tempData;
	}
	else {
		//How to find the end of the queue?
		struct element* temp = s->top;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		int tempData = temp->next->data;
		free(temp->next);
		temp->next = NULL;
		s->size--;
		return tempData;
	}
	
	
}

void printQ(struct queue* s) {
	struct element* temp = s->top;
	printf("queue contents: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Return 1 if the queues are identical and 0 if there are differences

int compareQueues(struct queue* q1, struct queue* q2) {
	
	//q1 and q2 are necessarily identical if they point at the same address
	if (q1 == q2) return 1; //If the two pointers point at the same list (ex:  compareQueues(x,x); )
	else if (q1->size != q2->size) return 0;
	else {
		struct element* temp1 = q1->top;
		struct element* temp2 = q2->top;

		

		while (temp1->next != NULL && temp2->next != NULL) {
			if (temp1->data != temp2->data) return 0;
			//Could also say:  if ((*temp1).data != (*temp2).data))
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1->next == NULL && temp2->next != NULL) return 0;
		if (temp2->next == NULL && temp1->next != NULL) return 0;
		return 1;

	}
}

