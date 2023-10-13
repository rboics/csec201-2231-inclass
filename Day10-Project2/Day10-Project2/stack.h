#pragma once
//Struct & Function definitio ns
#include <stdio.h>
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


struct stack {
	int size;
	struct element* top;

};

//Function prototype
void initializeStack(struct stack* s);
void push(struct stack* s, int data);
int pop(struct stack* s);
void print(struct stack* s);
