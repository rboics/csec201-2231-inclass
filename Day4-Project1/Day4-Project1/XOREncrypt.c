#include <stdio.h>
#include <string.h>

int main(void) {
	char text[20];
	char letter;

	printf("Enter the plain text: ");
	scanf("%s", text);
	scanf("%c", &letter); //Clear out the extra symbol in the input stream
	printf("Enter the single letter key: ");
	scanf("%c", &letter);

	for (int i = 0; i < strlen(text); i++) {
		text[i] = text[i] ^ letter;
	}
	//printf("Printing the cipher text: %s\n");
	for (int i = 0; i < strlen(text); i++) {
		printf("%d -", (int)text[i]);
	}
	printf("\nEncryption All done");
	for (int i = 0; i < strlen(text); i++) {
		text[i] = text[i] ^ letter;
	}
	printf("Plain text: %s\n", text);
}