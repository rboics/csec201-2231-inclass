#include <stdio.h>
#include <string.h>

int main(void) {
	int num;
	char name[20];
	printf("Enter number: ");
	scanf("%d", &num);
	printf("Enter your name: ");
	scanf("%s", name); // <<<<<
	printf("Hello %s\n", name);
	printf("Your number is: %d\n", num);
	printf("Your name is stored at address: %p\n", name);
	printf("Your number is stored at address: %p\n", &num);
	printf("End\n");
}