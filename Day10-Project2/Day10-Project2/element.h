#pragma once


//If I have the declaration:
// struct element x;
//Then I could write:
// x.data = 1;

//If I have a pointer:
// struct element * x = (struct element*)malloc(sizeof(struct element));
//Then
// x->data = 1;

struct element {
	int data;
	struct element* next;
};