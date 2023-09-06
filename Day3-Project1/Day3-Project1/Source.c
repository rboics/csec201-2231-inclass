#include <stdio.h>
#include <string.h>

int main(void) {
	int x = 5;
	char first[20];
	char second[20];

	x++;
	printf("Enter a word: ");
	scanf("%s", first);
	//printf("Enter a word: ");
	//scanf("%s", second);
	
	//%p --> Format specifier for memory addresses
	printf("Array begins at: %p\n", first);
	
	//strlen(param) calculates the string length of the parameter
	for (int i = 0; i < strlen(first); i++) {
		printf("Index %d is %c - %p\n", i, first[i], &(first[i]));
	}

	for (int i = 0; i < 20; i++) second[i] = 'A';

	//%p --> Format specifier for memory addresses
	printf("Array begins at: %p\n", second);

	//strlen(param) calculates the string length of the parameter
	for (int i = 0; i < strlen(second); i++) {
		printf("Index %d is %c - %p\n", i, second[i], &(second[i]));
	}
}