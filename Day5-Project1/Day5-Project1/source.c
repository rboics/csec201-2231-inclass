#include <stdio.h>

int main(void) {
	int x = 10;
	char word[20];
	for (int i = 0; i < 20; i++) word[i] = 'A';

	printf("%d - %p\n", x, &x);
	for(int i=0; i < 20; i++) printf("%c\n", word[i]);
	system("pause");
	printf("Made a change");
}