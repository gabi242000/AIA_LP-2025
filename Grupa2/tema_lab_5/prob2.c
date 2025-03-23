#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char c[25], aux;
    int x, y;
    printf("Introdu un cuvant: \n");
    scanf("%s",c);
    printf("Introdu pozitiile literelor pe care doresti sa le interschimbi: \n");
    scanf("%d %d", &x, &y);
    if((x<1||x>strlen(c))||(y<1||y>strlen(c)))
        {
            printf("Nu ai introdus pozitiile corect. \n");
            return 0;
        }
        aux=c[x];
        c[x]=c[y];
        c[y]=aux;
    printf("Sirul modificat este: %s",c);
    return 0;
}