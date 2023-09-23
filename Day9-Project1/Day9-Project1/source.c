#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int x = 5;
	int y = 6;
	int z = 7;

	//a, b, and c are pointers that reside on the stack
	//We'll use them to track locations of variables on the heap
	int* a;
	int* b;
	int* c;

	printf("&X: %p, X: %d\n&Y: %p, Y: %d\n&Z: %p, Z: %d\n", &x, x, &y, y,  &z, z);
	
	//Malloc -> memory allocation
	//One argument, the number of bytes to allocate on the heap
	//Allocates space on the heap
	//Malloc returns the address of the space allocated on the heap
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));

	//* means "dereference"
	//dereference means "value at that memory address"
	*a = 8;
	*b = 9;
	*c = 10;

	printf("&a: %p, a: %p, *a: %d\n", &a, a, *a);
	printf("&b: %p, b: %p, *b: %d\n", &b, b, *b);
	printf("&c: %p, c: %p, *c: %d\n", &c, c, *c);

	system("pause"); //Press any key to continue

	//Opposite of malloc:
	//Deallocates space on the heap
	//Deallocation -> marks the memory as available for reuse
	//(Like delete in Java)
	free(a);
	free(b);
	free(c);
}