#pragma once
//Struct & Function definitio ns
#include <stdio.h>

struct element {
	int* data;
	struct element* next;
};

struct stack {
	int size;
	struct element* top;
};

//Function prototype
void initializeStack(struct stack* s);
void push(struct stack* s, int data);
int pop(struct stack* s);
void print(struct stack* s);
