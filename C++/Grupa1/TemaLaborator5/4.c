#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char propozitie[100];
    int p;
    gets(propozitie);
    scanf("%d",&p);
    for(int i=0;i<strlen(propozitie);i++){
        if(propozitie[i]!=' '){
            int j=propozitie[i];
            propozitie[i]=j+p;
        }
    }
    printf("Aceasta este propozitie criptata pt p=%d:\n%s",p,propozitie);
    return 0;
}