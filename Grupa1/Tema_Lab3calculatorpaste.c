#include <stdio.h>

int main()
{
    int optiune;
    double num1, num2, rezultat;
 
    do{
        //Afisarea meniului
        printf("\nCalculator simplu\n");
        printf("1.Adunare\n");
        printf("2.Scadere\n");
        printf("3.Inmultire\n");
        printf("4.Impartire\n");
        printf("5.Iesire\n");
        printf("Alege o optiune: ");
        scanf("%d", &optiune);
 
        //Verificarea optiunii si efectuarea operatiei
        if(optiune>=1 && optiune <=4)
        {
            printf("Introdu doua numere: ");
            scanf("%lf %lf", &num1, &num2);
 
            switch (optiune){
            case 1:
                rezultat = num1 + num2;
                printf("Rezultatul: %.2lf\n", rezultat); //2l - long float cu exact 2 zecimale
                break;
            case 2:
                rezultat = num1-num2;
                printf("Rezultatul: %.2lf\n", rezultat);
                break;
            case 3:
                rezultat = num1*num2;
                printf("Rezultatul: %.2lf\n", rezultat);
                break;
            case 4:
                if(num2 != 0)
                {
                    rezultat = num1/num2;
                    printf("Rezultatul: %.2lf\n", rezultat);
                }
                else{
                    printf("Nu pune zero jupanule");
                }
                break;
 
            }
        }
        else if (optiune !=5)
        {
            printf("Optiune invalida! Incearca din nou.\n");
        }
    }while(optiune != 5); //programul se repeta pana cand utilizatorul alege sa iasa
 
    printf("Program incheiat.\n");
 
    return 0;
}   