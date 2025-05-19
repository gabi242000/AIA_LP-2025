#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100], auxiliar[100], aux;
    int poz1, poz2;
    printf("Introduceti un cuvant: ");
    scanf("%s", s);
    printf("Introduceti prima pozitie: ");
    scanf("%d", &poz1);
    printf("Introduceti a doua pozitie: ");
    scanf("%d", &poz2);
    if (poz1 >= 0 && poz1 < strlen(s) && poz2 >= 0 && poz2 < strlen(s)) {
        aux = s[poz1];
        s[poz1] = s[poz2];
        s[poz2] = aux;
        printf("Sirul dupa interschimbare: %s\n", s);
    } else {
        printf("Cel putin una dintre pozitii nu este valabila! Mai incearca.\n");
    }
    
}