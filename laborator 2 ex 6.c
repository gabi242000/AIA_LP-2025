#include <stdio.h>

int main()
{   
    int c;
    float p,t;
    printf("Introduceti pretul: ");
    scanf("%f",&p);
    printf("Introduceti codul de reducere: ");
    scanf("%d",&c);
    switch (c){
        case 1:
        t=p*0.9;
        printf("Pretul este: %.2f",t);
        break;
        
        case 2:
        t=p*0.8;
        printf("Pretul este: %.2f", t);
        break;
        
        case 3:
        t=p*0.7;
        printf("Pretul este: %.2f",t);
        break;
	
	default:
	printf("Cod invalid");
	break;
        
        
    }
    

    return 0;
}