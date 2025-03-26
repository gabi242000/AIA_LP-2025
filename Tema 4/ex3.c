#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
    char cuv[201],vocala[20]="aeiou";
    bool zibelina = true;

    printf("Introduceti cuv: ");
    fgets(cuv,201,stdin);
    cuv[strcspn(cuv,"\n")] = '\0';
    for(int i = 1; i < strlen(cuv); i++)
    {
        if(strchr(vocala,cuv[i]) != NULL && strchr(vocala,cuv[i-1]) != NULL)
            zibelina = false;
        if(strchr(vocala,cuv[i]) == NULL && strchr(vocala,cuv[i-1]) == NULL)
            zibelina = false;
    }
    if(zibelina)
        printf("DA");
    else
        printf("NU");
  
}