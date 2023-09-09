#include <stdio.h>
#include <string.h> //Don't use <string> -> CPP, <string.h> -> c strings

int main(void) {
	int x = 10;
	int y = 12;

	// &, when used as a binary mathematical operator, is mathematical and
	printf("%d and %d = %d\n", x, y, x & y);
	// |, when used as a binary mathematical operator, is mathematical or
	printf("%d or  %d = %d\n", x, y, x | y);
	// ^, when used as a binary mathematical operator, is mathematical xor
	printf("%d xor %d = %d\n", x, y, x ^ y);
}
