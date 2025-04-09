#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cripteaza(char sir[], int key){
    for (int i = 0; sir[i] != '\0'; i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = (sir[i] - 'a' + key) % 26 + 'a';
        }
        else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = (sir[i] - 'A' + key) % 26 + 'A';
        }
    }   
}

void decripteaza(char sir[], int key){
    for (int i = 0; sir[i] != '\0'; i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = (sir[i] - 'a' - key+26) % 26 + 'a';
        }
        else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = (sir[i] - 'A' - key+26) % 26 + 'A';
        }
    }  
}

int main(){
    char sir[101], t[101];
    int key,compara;
    printf("Introdu un sir: ");
    fgets(sir,101,stdin);
    for (int i = 0; sir[i] != '\0'; i++) t[i]=sir[i];
    //printf("Sirul introdus este: %s",t);

    printf("Introdu pozitia: ");
    scanf("%d",&key);

    cripteaza(sir,key);
    printf("Sirul criptat: %s",sir);

    decripteaza(sir,key);
    printf("Sirul decriptat: %s",sir);

    compara=strcmp(sir,t);
    if(compara==0) printf("Sirul a fost decriptat corect");
    else printf("Sirul nu a fost decriptat corect");
    
    return 0;
}