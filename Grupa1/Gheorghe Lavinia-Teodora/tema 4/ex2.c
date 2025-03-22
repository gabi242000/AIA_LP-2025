#include <stdio.h>
#include <string.h>

char s[101], aux;
int x, y;

int main() {
    printf("Introduceti un cuvant: ");
    scanf("%s", &s);
    printf("Introduceti doua pozitii pe care le doriti interschimbate: ");
    scanf("%d%d",x, y);

    if((x < 0 || x > strlen(s)) || (y < 0 || y > strlen(s))) {
        printf("Pozitia introdusa este invalida!");
        return 1;
    }

    aux = s[x];
    s[x] = s[y];
    s[y] = aux;

    printf("Cuvantul in forma finala este: %s", s);

    return 0;
}
