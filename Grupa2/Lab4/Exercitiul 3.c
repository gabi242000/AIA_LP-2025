#include <stdio.h>
#include <string.h>

int n, a[100][100];

int main() {

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i <= j)
				a[i][j] = i + j + 1;
			else a[i][j] = a[j][i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	

	return 0;
}
