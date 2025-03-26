#include<stdio.h>
#include<string.h>
int main()
{
    char prop[201];
    int poz1,poz2;

    printf("Introduceti propozitia: ");
    fgets(prop,201,stdin);
    printf("Introduceti cele 2 pozitii: ");
    scanf("%i %i",&poz1,&poz2);
    char aux = prop[poz1];
    prop[poz1] = prop[poz2];
    prop[poz2] = aux;

    printf("%s ",prop);
   
  
}