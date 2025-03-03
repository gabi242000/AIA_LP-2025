#include <stdio.h>

int main() {

	int salariu_brut, impozit;

	printf("Introduceti salariul brut: ");
	scanf_s("%d", &salariu_brut);
	printf("Optiuni: \n");
	printf("Tasta 1. Salariu pentru angajat full-time (25%% impozit)\n");
	printf("Tasta 2. Salariu pentru contract de colaborare (10%% impozit)\n");
	printf("Tasta 3. Salariu pentru PFA (5%% impozit)\n");
	printf("Introduceti optiunea dorita: ");
	scanf_s("%d", &impozit);

	switch (impozit) {

		case 1:
			printf("Salariul net este: %d\n", salariu_brut - (salariu_brut * 25 / 100));
			break;
		case 2:
			printf("Salariul net este: %d\n", salariu_brut - (salariu_brut * 10 / 100));
			break;
		case 3:
			printf("Salariul net este: %d\n", salariu_brut - (salariu_brut * 5 / 100));
			break;
		default:
			printf("Optiune invalid\n");
			break;
	}

	return 0;
}
