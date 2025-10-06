#include <stdio.h>

int main() {
    int s, t, i = 0;

    printf("Salariu brut: ");
    scanf("%d", &s);
    printf("Tip contract (1-full-time, 2-colaborare, 3-PFA): ");
    scanf("%d", &t);

    if (t == 1) i = 25;
    if (t == 2) i = 10;
    if (t == 3) i = 5;
    if (i == 0) return printf("Eroare: cod invalid!\n"), 1;

    printf("Salariu net: %d\n", s * (100 - i) / 100);
    return 0;
}