#include <stdio.h>
#include <stdlib.h>

typedef int (*mathF)(int, int);

struct example {
	int* first;
	char* second;
	mathF m;
};

int add(int x, int y) {
	return x + y;
}



int main(void) 
{


	struct example e;

	int num = 10;
	char letter = 'A';
	e.first = &letter;
	e.second = &num;

	printf("%d %c\n", *e.second, *e.first);

	//Create an array of 10 integers; normal behavior
	int* array = malloc(10 * sizeof(int));

	//Creates an array that holds 10.5 integers; normal behavior FOR C ONLY
	int* array2 = malloc(42);

	for (int i = 0; i < 42; i++) {
		((char*)array2)[i] = 'A';
	}
	
	e.m = add;
	int result = e.m(5, 6);


	printf("%p\n", &e);
	printf("%d\n", result);
	//system("pause");

	int x = 2;		//0000 0010
	printf("Shift Left 1: %d\n", x << 1); //Shift the digits in x left by 1
										  //0000 0100
	printf("Shift Left 2: %d\n", x << 2); //Shift the digits in x left by 2
	//0000 1000
	printf("Shift Right 1: %d\n", x >> 1); //Shift the digits in x right by 1
	//0000 0001
}