#include <stdio.h>

int main()
{
    int n,F1=0,F2=1,FN;
    printf("S I R U L   L U I   F I B O N A C C I\nIntrodu un numar (testeaza-ti limitele): ");
    scanf("%d",&n);
    printf("\n\nS T A R T ! ! !\n");
    while(F2<n)
    {
        FN=F1+F2;
        F1=F2;
        F2=FN;
        if(F2<n)
            printf("\n\n%d = %d + %d \n(F(n) = %d; F(n-1) = %d, F(n-2) = %d)",FN,F2,F1,FN,F2,F1);
    }
    return 0;
}