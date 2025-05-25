#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

sortareVector(int v[], int n) {
	int i, j, aux;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

cautareBinara(int v[], int n, int x) {
	int st = 0, dr = n - 1, mij;
	while (st <= dr) {
		mij = (st + dr) / 2;
		if (v[mij] == x)
			return mij + 1;
		else if (v[mij] < x)
			st = mij + 1;
		else
			dr = mij - 1;
	}
	return -1;
}

int main() {

	int n, i, x, v[100];

	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);

	printf("Introduceti elementele vectorului: ");
	for (i = 0; i < n; i++) 
		scanf("%d", &v[i]);
	
	sortareVector(v, n);
	printf("Vectorul sortat: ");
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\nIntroduceti elementul cautat: ");
	scanf("%d", &x);

	int poz = cautareBinara(v, n, x);

	if (poz != -1)
		printf("Elementul %d se afla pe pozitia %d\n", x, poz);
	else
		printf("Elementul %d nu se afla in vector\n", x);

	return 0;
}
