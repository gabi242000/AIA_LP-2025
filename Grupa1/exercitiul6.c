#include <stdio.h>
int main (){
    int x, y, z;
    printf("Introduceti pretul produsului:");
    scanf("%d", &x);
    printf("Introduceti codul de reducere(1, 2 sau 3):");
    scanf("%d", &y);
    switch (y) {
        case 1:
            z = x * 0.9;  
            break;
        case 2:
            z = x * 0.8;  
            break;
        case 3:
            z = x * 0.7;  
            break;
        default:
            printf("Nu ai selectat un cod de reducere valid!\n");
          
}
    printf("Pretul final este: %d", z);
    return 0;
}