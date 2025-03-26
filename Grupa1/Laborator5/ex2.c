#include <stdio.h>
#include <string.h>

int main()
{
    char cuvant[100];
    printf("Introduceti cuvantul: ");
    fgets(cuvant, 100, stdin);

    int len = strlen(cuvant);
    if (len > 0 && cuvant[len - 1] == '\n') {
        cuvant[len - 1] = '\0';
    }

    int x, y;
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < len && y >= 0 && y < len) {
        char temp = cuvant[x];
        cuvant[x] = cuvant[y];
        cuvant[y] = temp;
    } else {
        printf("Pozitii invalide\n");
        return 1;
    }

    for (int i = 0; cuvant[i] != '\0'; i++) {
        printf("%c", cuvant[i]);
    }
    printf("\n");

    return 0;
}
