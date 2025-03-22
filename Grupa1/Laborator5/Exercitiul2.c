#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    char s[100],aux;
    int x,y;

    printf("Introdu un cuvant:");
    scanf("%s",&s);

    printf("Introdu doua pozitii\n");

    while(scanf("%d",&x) && scanf("%d",&y)){
        if(x>=0 && x<=strlen(s)-1 && y>=0 && x<=strlen(s)-1) break;
        else printf("Pozitiile date nu sunt valide\n");
    }

    aux = s[x];
    s[x]=s[y];
    s[y]=aux;
    
    printf("Cuvantul rezultat este: %s",s);
    
}