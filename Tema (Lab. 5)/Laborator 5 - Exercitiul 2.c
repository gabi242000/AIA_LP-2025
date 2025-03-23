#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int x,y;
    char Cuv[51],litera=' ';
    printf("Un sir de caractere va rog: ");
    fgets(Cuv,51,stdin);
    Cuv[strcspn(Cuv,"\n")]=0;
    printf("Introdu coordonata X (prima coordonata): ");
    scanf("%d",&x);
    printf("Introdu coordonata Y (a doua coordonata): ");
    scanf("%d",&y);
    litera = Cuv[x-1];
    Cuv[x-1] = Cuv[y-1];
    Cuv[y-1] = litera;
    printf("Rezultatul: %s",Cuv);
    return 0;
}