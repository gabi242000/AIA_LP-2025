#include <stdio.h>
#include <string.h>

int main(){
    char cuvant[100];
    int x,y;

    printf("Introduceti cuvantul format din litere mici:");
    scanf("%s", cuvant);

    printf("Introduceti prima pozitie: ");
    scanf("%d", &x);

    printf("Introduceti a doua pozitie: ");
    scanf("%d", &y);

    int lungime=strlen(cuvant);
    if(x>=0 && x<lungime && y>=0 && y<lungime){
        char aux=cuvant[x];
        cuvant[x]=cuvant[y];
        cuvant[y]=aux;
    }
    printf("%s\n", cuvant);

    
    return 0;

}