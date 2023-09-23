#include <stdio.h>

int fact(int n) {
	int product = 1;
	printf("n: %p, product: %p\n", &n, &product);
	for (int i = 1; i <= n; i++) product = product * i;
	return product;
}

//Pass by Value --> New copy of the variable
int recFact(int n) {
	int product = 1;
	printf("n: %p, product: %p\n", &n, &product);
	if (n == 1) return 1;
	else {
		product = n * recFact(n - 1);
		return product;
	}
}

//Pass-By-Value
int addOne(int n) {
	n++;
	printf("n - %d\n", n);
}

//Pass-by-Reference
//* in a declaration means that we've got a ptr
int addOnePbR(int* n) {
	//* as a unary operator (operator with one operand) means "dereference", opposite of &
	//Just like & means "address of", * means "value at address"
	printf("&n=%p\n", &n);
	(*n)++;
	printf("n - %d\n", *n);
}


int main(void) {
	int x;
	int res;
	printf("x: %p, res: %p\n", &x, &res);
	printf("Enter a number: ");
	scanf("%d", &x);
	//res = recFact(x);
	//printf("Factorial: %d", res);
	addOnePbR(&x);
	printf("After AddOne: %d\n", x);

}