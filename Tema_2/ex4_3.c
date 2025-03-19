   #include <stdio.h>
   int main()
{ 
    //ex_4.3
    int N,i,j;
    printf("Introdu un numar pentru a realiza piramida: ");
    scanf("%d",&N);
    for (i=0; i<N;i++) 
    {
        for (j=0;j<N-i;j++) 
        {
            printf(" ");
        }
        for (j=0; j<2*i-1;j++)
    {
            printf("*");
    }
    printf("\n");
    }
    return 0;
}