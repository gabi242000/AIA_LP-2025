//
#ex5
#include <iostream>
using namespace std;
int main(){
    int nota;
    cout<<"Introduceti o nota de la 1 la 10:";
    cin>>nota;
    switch(nota){
        case 10:
            cout<<"Excelent!"<<endl;
            break;
        case 9:
            cout<<"Foarte bine!"<<endl;
            break;
        case 8:
            cout<<"Bine1"<<endl;
            break;
        case 7:
            cout<<"Acceptabil1"<<endl;
            break;
        case 6:
            cout<<"Satisfacator!"<<endl;
            break;
        case 5:
            cout<<"Suficient!"<<endl;
            break;
        case 4:
        case 3:
        case 2:
        case 1:
            cout<<"Insuficient!"<<endl;
            break;
        default:
            cout<<"Ai introdus o nota invalida.Mai incearca!!!"<<endl;
            break;
    }
    return 0;
}
#ex6

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

#ex7
#include <stdio.h>
int main()
{
    float sal_brut,sal_net;
    int cod;
    printf("Introduceti salariul brut:");
    scanf("%f",&sal_brut);
    printf("Introduceti tipul contractului(corespunzatoare fiecarui tip de cod.)");
    scanf("%d",&cod);
    switch(cod)
    {
        case 1:
            sal_net=sal_brut-(sal_brut*0.25);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
        case 2:
            sal_net=sal_brut-(sal_brut*0.10);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
        case 3:
            sal_net=sal_brut-(sal_brut*0.05);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
    default:
        printf("Cod de contract invalid. Vă rugăm să introduceți un cod valid (1, 2 sau 3).\n");
        break;
    }
    return 0;
}