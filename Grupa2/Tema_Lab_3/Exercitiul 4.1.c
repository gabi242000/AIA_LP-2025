#include <stdio.h>

int n;

int main() {

	printf("Introduceti numarul: ");
	scanf_s("%d", &n);

	printf("Numarele pare pana la nummarul %d sunt: ", n);

	for (int i = 0; i <= n; i += 2)
		printf("%d ", i);

	return 0;
}