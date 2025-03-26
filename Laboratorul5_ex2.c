#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char cuvant[101];
    int x,y,i;
    printf("Introdu un cuvant: ");
    scanf("%s",cuvant);
    printf("Introdu pozitiile literelor care urmeaza sa fie interschimbate: ");
    scanf("%d %d",&x, &y);
    if(x<0 || x>strlen(cuvant)&&y<0 || y>strlen(cuvant)){
        printf("Pozitii invalide\n");
        return 1;
    }
    char literax=cuvant[x];
    char literay=cuvant[y];
    printf("Litera de la pozitia %d: %c\n",x,literax);
    printf("Litera de la pozitia %d: %c\n",y,literay);
    for(i=0; cuvant[i]!='\0'; i++){
        if(i==x) cuvant[i]=literay;         
        if(i==y) cuvant[i]=literax;
    }
    printf("Noul cuvant este: %s",cuvant);
    return 0;
}