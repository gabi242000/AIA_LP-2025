#include <stdio.h>
#include <string.h>
int main()
{
    char prop[201];
    int p;

    printf("Introduceti cuv: ");
    fgets(prop, 201, stdin);
    prop[strcspn(prop, "\n")] = 0;
    printf("Introduceti p: ");
    scanf("%i ", &p);

    for (int i = 0; i < strlen(prop); i++)
        if (prop[i] != ' ')
            prop[i] += p;

    printf("%s", prop);
}