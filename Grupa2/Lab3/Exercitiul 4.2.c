#include <stdio.h>

int n, a = 0, b = 1, c;

int main() {

	printf("Introduceti numarul: ");
	scanf_s("%d", &n);

	printf("Primele %d numere din sirul Fibonacci sunt: %d %d ", n, a, b);

	for (int i = 1; i <= n-2; i++) {
		c = a + b;
		a = b;
		b = c;
		printf("%d ", c);

	}
		

	return 0;
}
