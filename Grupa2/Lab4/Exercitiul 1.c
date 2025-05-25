#include <stdio.h>
#include <string.h>

int n, a[100][100], suma_rand, suma_rand_max, rand;

int main() {

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &a[i][j]);

	for (int i = 0; i < n; i++) {
		suma_rand = 0;
		for (int j = 0; j < n; j++)
			suma_rand += a[i][j];
		if (suma_rand > suma_rand_max) {
			suma_rand_max = suma_rand;
			rand = i + 1;
		}
	}

	printf("Suma maxima este %d pe randul %d", suma_rand_max, rand);

	return 0;
}
