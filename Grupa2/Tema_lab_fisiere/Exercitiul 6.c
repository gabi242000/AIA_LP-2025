#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE *fisier;
	int n, i;
	int *v;

	fisier = fopen("vector.txt", "w");
	if (f == NULL) {
		printf("Eroare la crearea fișierului.\n");
		return 1;
	}
	
	n = 5;
	fprintf(fisier, "%d ", n);
	for (i = 0; i < n; i++) {
		fprintf(fisier, "%d ", (i + 1) * 10);
	}
	fclose(fisier);
	
	fisier = fopen("vector.txt", "r");
	if (fisier == NULL) {
		printf("Eroare la deschiderea fișierului.\n");
		return 1;
	}
	fscanf(fisier, "%d", &n); 
	
	v = (int *)malloc(n * sizeof(int));
	if (v == NULL) {
		printf("Eroare la alocarea memoriei.\n");
		fclose(fisier);
		return 1;
	}
	
	for (i = 0; i < n; i++) {
		fscanf(fisier, "%d", &v[i]);
	}
	fclose(fisier);
	
	printf("Vectorul citit din fisier este:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	
	free(v);
	
	return 0;
}