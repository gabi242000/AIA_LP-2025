//ex6

#include <stdio.h>
int main(){
    float pret;
    int cod_reducere;
    printf("Introdu pretul unui produs:");
    scanf("%f", &pret);
    printf("Introdu codul de reducere (1,2 sau 3):");
    scanf("%d",&cod_reducere);

    switch(cod_reducere)
    {
        case 1:
            printf("Pretul final dupa reducere este %.2f\n",pret*0.9);
            break;
        case 2:
            printf("Pretul final dupa reducere este %.2f\n",pret*0.8);
            break;
        case 3:
            printf("Pretul final dupa reducere este %.2f\n",pret*0.7);
            break;
    default:
        printf("Codul introdus este invalid!Te rog sa introduci alt cod (1,2 sau 3)");
        break;
    }
    
    return 0;
}