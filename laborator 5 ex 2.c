#include <stdio.h>
#include <string.h>

char* schimba_litere(char cuvant[], int x, int y) {
    int lungime = strlen(cuvant);
    if (x >= 0 && x < lungime && y >= 0 && y < lungime) {
        char temp = cuvant[x];
        cuvant[x] = cuvant[y];
        cuvant[y] = temp;
    } else {
        printf("Pozitii invalide!\n");
    }

    return cuvant;
}

int main() {
    char cuvant[100];
    int x, y;
    printf("Introduceți un cuvânt: ");
    scanf("%s", cuvant);
    printf("Introduceți două poziții x, y: ");
    scanf("%d %d", &x, &y);
    printf("Cuvântul modificat: %s\n", schimba_litere(cuvant, x, y));

    return 0;
}
