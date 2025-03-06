#include <stdio.h>

int main() {
    float pret, reducere;
    int cod;

    printf("Introdu un pret: ");
    scanf("%f", &pret);
    printf("Introdu codul de reducere: ");
    scanf("%d", &cod);

    
    if (cod == 1)
        reducere = pret * 0.1;
    else if (cod == 2)
        reducere = pret * 0.2;
    else if (cod == 3)
        reducere = pret * 0.3;
    else {
        printf("Codul introdus nu exista!\n");
        
    }

    printf("Pretul final este: %f", pret-reducere);
    return 0;
}