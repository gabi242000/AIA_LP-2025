#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char cuvant[50];
    int lungime,i,f=0;
    printf("Introdu un cuvant: ");
    scanf("%s",cuvant);
    lungime=strlen(cuvant);
    if(cuvant[0]=='z'){
        if(lungime % 2==0) {
            for(i=1; i<lungime; i=i+2) {
                if(cuvant[i]=='a' || cuvant[i]=='e' || cuvant[i]=='i' || cuvant[i]=='o' || cuvant[i]=='u') f++;
            }
        }
    }
    if(f==lungime/2) printf("Ai introdus un cuvant frumos.");
    else printf("Nu ai introdus un cuvant frumos.");
    return 0;
}