#include <stdio.h>
int main(){
float salariubrut, salariunet, impozit;
int cod;
printf("Care este salariul brut?: ");
scanf("%f", &salariubrut);
printf("introduceti codul contractului:1, 2 sau 3: ");
scanf("%d", &cod);
switch(cod){
    case 1:
    impozit= 0.25;
    break;
    case 2:
    impozit= 0.10;
    break;
    case 3:
    impozit= 0.05;
    break;
    default:
    printf("Nu ai selectat un cod valid!");
    return 1;

}
salariunet = salariubrut- (salariubrut*impozit);
printf("Salariul tau net este de %f", salariunet);
return 0;
}