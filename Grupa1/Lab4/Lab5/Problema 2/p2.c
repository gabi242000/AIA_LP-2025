#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[25], aux[25];
    int x, y;
    printf("Introduce-ti sirul:");
    scanf("%s",s);
    printf("Introduce-ti pozitile de interchimbat(2):");
    scanf("%d", &x);
    scanf("%d", &y);

    strcpy(aux, s);

    strcpy(aux + x, s + y);
    strcpy(aux + x + 1, s + x + 1);
    strcpy(aux + y, s + x);
    strcpy(aux + y + 1, s + y + 1);

    printf("Sirul procesat este: %s", aux);
    return 0;
}