#pragma once
//Struct & Function definitio ns
#include <stdio.h>
#include <stdlib.h>
#include "element.h"
//Comments here based on question in class
//Meaning #1 - z = y * z;
//Multiplication

//Meaning #2 - int * x;
//Declaring a variable that can hold the memory addr of an integer

//Meaning #3 - *x = 6;
//Dereferences the address in x to find
//the actual integer
//x = 6;
//End comments based on question in class


struct queue {
	int size;
	struct element* top;

};

//Function prototype
void initializeQueue(struct queue* s);
void enqueue(struct queue* s, int data);
int dequeue(struct queue* s);
void printQ(struct queue* s);
#pragma once
