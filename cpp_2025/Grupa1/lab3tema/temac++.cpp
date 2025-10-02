#include <iostream>

using namespace std;

void ex1()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
            cout<<i<<" ";
    }
}

void ex2()
{
    int n;
    cin>>n;
    cout<<"Primele "<<n<<" numere fibbonaci sunt: ";
    if(n == 1)
    {
        cout<<"0";
        return;
    }
    if(n == 2)
    {
        cout<<"0 1";
        return;
    }
    int cif = 1 , ultima_cif = 1;
    cout<<"0 1 ";
    for(int i = 1; i < n-1 ; i++)
    {
        cout<<cif<<" ";
        int aux = cif;
        cif+=ultima_cif;
        ultima_cif = aux;
    }
}

void ex3()
{
    int n;
    cin>>n;
    int width = 2 * n - 1;
    
    for (int i = 1; i <= n; i++) {
        int stars = 2 * i - 1;
        int spaces = (width - stars) / 2;        
        cout << string(spaces, ' ') << string(stars, '*') << endl;
    }
}
int main()
{
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        default:
            cout<<"Invalid input";
    }
    return 0;
}