/**
Scrie o funcție recursivă care calculează cel mai mare divizor comun (CMMD) a două 
numere 
a 
Folosește relația: 
și 
b, 
➢ cmmdc(a, b) = cmmdc(b, a % b) 
folosind 
algoritmul 
➢ Baza recursiei este când b == 0, caz în care cmmdc(a, 0) = a. 
**/
#include <stdio.h>

int euclid (int a, int b){
    if (b == 0) return a;
    if (a == 0) return b;
    if (a > b) return euclid (a-b, b);
    if (b > a) return euclid (a, b-a);
}

int main(){
    int a, b;
    printf("Introdu numarul 1: ");
    scanf("%d", &a);
    printf("Introdu numarul 2: ");
    scanf("%d", &b);
    if (a == b) printf ("CMMDC = %d", a);
    else printf ("CMMDC = %d", euclid (a, b));
    return 0;
}