#include <stdio.h>
#include <string.h>

int n, a[100][100];

int main() {

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &a[i][j]);

	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			if (a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1])
				printf("Un varf este %d si se afla pe pozitia [%d][%d]\n", a[i][j], i, j);
				
	

	return 0;
}