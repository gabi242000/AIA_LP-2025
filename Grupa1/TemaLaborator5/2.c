#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char sir[100];
    gets(sir);
    int poz1,poz2;
    scanf("%d",&poz1);
    scanf("%d",&poz2);
    char aux;
    aux=sir[poz1];
    sir[poz1]=sir[poz2];
    sir[poz2]=aux;
    printf("%s",sir);
    return 0;
}