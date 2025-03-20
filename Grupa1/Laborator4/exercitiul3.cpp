#include <iostream>

int main()
{
    int N;
    std::cout<<"Introdu numarul de linii si coloane ale matricei: ";
    std::cin>>N;
    int a[N][N];
    int i,j;

    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                a[i][j]=i+j+1;
                a[j][i]=a[i][j];

            }
        }
    std::cout<<"Matricea rezultata este:\n";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            std::cout<<a[i][j]<<" ";
            
        }std::cout<<"\n";
    }
    
    return 0;
}
