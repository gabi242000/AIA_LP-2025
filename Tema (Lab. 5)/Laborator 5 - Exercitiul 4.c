#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int p;
    char Cuv[51];
    printf("Introdu cuvantul: ");
    fgets(Cuv,51,stdin);
    Cuv[strcspn(Cuv,"\n")]=0;
    printf("\nIntrodu si numarul lui P: ");
    scanf("%d",&p);
    for(int i=0;i<strlen(Cuv);i++)
        printf("%c",Cuv[i]+p);
    return 0;
}