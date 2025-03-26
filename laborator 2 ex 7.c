#include <stdio.h>

int main()
{   
    int c;
    float b,n;
    printf("Introduceti salariul brut: ");
    scanf("%f",&b);
    printf("Introduceti tipul contractului: ");
    scanf("%d",&c);
    switch (c){
        case 1:
        n=b-(b*0.25);
        printf("Salariul net este: %.2f",n);
        break;
        
        case 2:
        n=b-(b*0.1);
        printf("Salariul net este: %.2f",n);
        break;
        
        case 3:
        n=b-(b*0.05);
        printf("Salariul net este: %.2f",n);
        break;
        
        default:
        printf("Tipul contractului nu este valid");
        break;
    }
    

    return 0;
}