#include <stdio.h> // stdio -> standard input/output
//Data Types -> int, bool, char, float, double
#include <string.h> // string.h -> string processing functions

// int -> return type
// main -> funtion name
// void -> argument list (ie: no arguments)
int main(void) {
	char name[20]; // Character array (String) of at most 20 characters
	printf("Enter your name: ");
	scanf("%s", name);	// 2 arguments. 1st is format specifier (data type)
						// %s -> string (only possible because string.h
						// %c - char, %d is int, %f is float
						// 2nd argument is the location to store the input
	printf("Hello %s", name); // format specifiers are used as placeholders

}