#include <stdio.h>

int main() {

	int pret, cod_reducere;

	printf("Introduceti pretul produsului: ");
	scanf_s("%d", &pret);
	printf("Optiuni cod de reducere: \n");
	printf("Tasta 1. pentru 10%% reducere\n");
	printf("Tasta 2. pentru 20%% reducere\n");
	printf("Tasta 3. pentru 30%% reducere\n");
	printf("Introduceti codul de reducere: ");
	scanf_s("%d", &cod_reducere);

	switch (cod_reducere) {

	case 1:
		printf("Pretul produsului cu reducere de 10%% este: %d\n", pret - (pret * 10 / 100));
		break;
	case 2:
		printf("Pretul produsului cu reducere de 20%% este: %d\n", pret - (pret * 20 / 100));
		break;
	case 3:
		printf("Pretul produsului cu reducere de 30%% este: %d\n", pret - (pret * 30 / 100));
		break;
	default:
		printf("Cod de reducere invalid\n");
		break;
	}

	return 0;
}
