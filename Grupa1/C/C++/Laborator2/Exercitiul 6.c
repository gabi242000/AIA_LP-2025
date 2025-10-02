#include <stdio.h>

int main(){
    float pret;
    char cod;
    printf("Introduceti pretul unui produs:"); 
    scanf("%f",&pret);

    printf("Pretul initial al produsului este : %0.2f",pret); printf("\n");
    printf("Introduceti un cod de reducere:\n");
    printf("a. 10 la suta reducere\n");
    printf("b. 30 la suta reducere\n");
    printf("c. 30 la suta reducere\n");

    scanf(" %c",&cod);

    switch (cod)
    {
    case 'a':
        printf("Ati ales codul de 10 la suta reducere!");
        break;
    case 'b':
        printf("Ati ales codul de 20 la suta reducere!");
        break;
    case 'c':
        printf("Ati ales codul de 30 la suta reducere!");
        break;
    
    default:
        printf("Nu ati introdus un cod valid");
        break;
    }



    
    
   
}