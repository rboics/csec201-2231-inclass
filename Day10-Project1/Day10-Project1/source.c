#include <stdio.h>
#include <string.h>
#include <math.h>


//User-defined coordinate "object"
struct coordinate {
	int x;
	int y;
};

void initialize(struct coordinate* c) {
	(*c).x = 0;
	(*c).y = 0;
}

double dist(struct coordinate f, struct coordinate s) {
	
	//sqrt(somevalue)
	double deltaX = (double)f.x - (double)s.x;
	double deltaY = (double)f.y - (double)s.y;
	double result = sqrt(deltaX*deltaX + deltaY*deltaY);
	return result;
}


int main(void) 
{
	//Declaring a instance of type coordinate
	//What really happens is that structs are just short-hand for 
	//multi-variable allocation
	struct coordinate first;
	struct coordinate second;
	double distance;
	initialize(&first);
	initialize(&second);

	printf("%p, %p\n", &first, &second);

	printf("Enter first x value: ");
	scanf("%d", &(first.x));
	printf("Enter first y value: ");
	scanf("%d", &(first.y));

	printf("Enter second x value: ");
	scanf("%d", &(second.x));
	printf("Enter first y value: ");
	scanf("%d", &(second.y));

	distance = dist(first, second);

	//%lf - format specifier for double. %f is "float". In c, 'l' is general modifier
	//that means "long"
	printf("The distance between the two points is: %lf", distance);
}
