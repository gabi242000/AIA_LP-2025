#include<stdio.h>
#include<string.h>
int main()
{
    char prop[201];
    printf("Introduceti o propozitie: ");
    fgets(prop,201,stdin);
    prop[strcspn(prop,"\n")] = 0;
    for(int i = 0; i < strlen(prop); i++)
        prop[i]=tolower(prop[i]);
    
    printf("%s ",prop);

}