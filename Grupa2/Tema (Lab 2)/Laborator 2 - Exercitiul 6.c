#include <stdio.h>

int main()
{
    int pret,proc,red;
    printf("Introdu pretul produsului: ");
    scanf("%d",&pret);
    printf("\nIntrodu si codul procentului (1, 2 sau 3): ");
    scanf("%d",&proc);
    if(proc<=3 && proc>=1){
        printf("\nPretul de %d de lei va avea parte de o reducere de %d la suta. ",pret,proc*10);
        switch(proc)
        {
            case 1:
                red=pret*10/100;
                break;
            case 2:
                red=pret*20/100;
                break;
            case 3:
                red=pret*30/100;
                break;
            }
            printf("\nPretul nou va fi de %d de lei.",pret-red);
    }
    else
        printf("EROARE: Numarul codului nu este cuprins intre 1-3.");
    return 0;
}