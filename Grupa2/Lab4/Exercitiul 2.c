#include <stdio.h>
#include <string.h>

int n, v[100], aux;

int main() {

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &v[i]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n - 1; j++)
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}

	for (int i = 0; i < n; i++)
		if (v[i] == v[i + 1]) {
			for (int j = i; j < n; j++)
				v[j] = v[j + 1];
			n--;
		}

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	return 0;
}
