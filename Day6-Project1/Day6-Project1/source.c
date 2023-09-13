#include <stdio.h>


int main(void) {
	int x = 10;  //Memory is allocated for X on the stack
	//Pointer that can hold the memory address of an integer
	//* in this context -> A variable that can hold an address of a variable of the 
	//the preceeding datatype
	int* ptr;


	//&x --> "memory address of"
	printf("%p\n", &x);
	ptr = &x; //Ptr stores the address of x;
	printf("%p\n", ptr);
	printf("%p\n", &ptr);// This would print the memory of ptr not the memory addr that ptr stores
						 //(ie: prints addr of ptr not addr of x)

	printf("The contents of X: %d\n", x);
	printf("The address of X: %p\n", &x);
	printf("The contents of ptr: %p\n", ptr);
	printf("The address of ptr: %p\n", &ptr);
	//* in this context indicates to fetch the data at the memory addr stored ptr
	printf("The contents of X: %d\n", *ptr); 
}