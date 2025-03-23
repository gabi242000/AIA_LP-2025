#include <iostream>

using namespace std;

void ex1()
{
    int n, i, j, s=0, max=-9999, rand=0;
    cin>>n;
    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
            s+=a[i][j];
        }
        if(max<=s)
        {
            max=s;
            rand=i+1;
        }
        s=0;
    }
    cout<<"randul cel mai mare este:"<<rand<<" cu suma:"<<max;
}
void ex2()
{
    int n, i, j;
    cin>>n;
    int a[n], c;
    for(i=0; i<n; i++)
        cin>>a[i];
    for (i=0; i<n; i++) 
    {
        for (j=i; j<n; j++) 
        {
            if (a[i]>a[j]) 
            {
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
    //elimina ineficient
    for(i=0; i<n-1; i++)
    {
        if(a[i]==a[i+1])
        {
            for(j=i; j<n; j++)
                a[j]=a[j+1];
            n--;//nu elimina elementele din coada idk daca e o problema
            i--;//repeta pasul anterior cu numerele noi
        }
    }
        
    for(i=0; i<n; i++)
        cout<<a[i];
}
void ex3()
{
    int n, i, j;
    cin>>n;
    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            //presupun ca partea superioara si inferioara
            //se refera la diagonala principala
            if(i<=j)
                a[i][j]=i+j+1;
            else
                a[i][j]=a[j][i];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void ex4()
{
    //presupun ca varfurile nu pot exista pe margine
    //fiindca nu au toti vecinii
    int n, i, j;
    cin>>n;
    int a[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=1; i<n-1; i++)
    {
        for(j=1; j<n-1; j++)
        {
            if(a[i][j]>a[i-1][j] &&
                a[i][j]>a[i+1][j] &&
                a[i][j]>a[i][j-1] &&
                a[i][j]>a[i][j+1])
                cout<<a[i][j];
        }
    }
}
int main()
{
    
    return 0;
}