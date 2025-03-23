#include <iostream>
#include <cstring>

using namespace std;

void ex1()
{
    char a[101];
    cin.getline(a, 100);
    strupr(a);
    cout<<a;
}
void ex2()
{
    int x, y, c;
    char a[101];
    cin.getline(a, 100);
    cin>>x>>y;
    c=a[x-1];
    a[x-1]=a[y-1];
    a[y-1]=c;
    cout<<a;
}
void ex3()
{
    //s-a scos algoritmul de backtracking
    //din programa de cativa ani de la mate info, acum se invata
    //doar principiul pe care merge si nu codul 

    //dar daca n-am inteles cerinta si trb defapt sa verific daca cuvantul e "frumos":
    char a[101];
    int ok=1,i,x;
    cin.getline(a, 100);
    x=strlen(a);
    if(a[0]!='z' && x%2!=0)
        ok=0;
    for(i=1;i<x;i++)
    {
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
        {
            if(i%2==0)
                ok=0;
        }
        else if(i%2==1)
            ok=0;
    }       
    if(ok==1)
        cout<<"Cuvantul este frumos";
    else
        cout<<"Cuvantul NU este frumos";
}
void ex4()
{
    int i, x, p;
    char a[101];
    cin.getline(a, 100);
    cin>>p;
    x=strlen(a);
    for(i=0; i<x; i++)
    {
        if(a[i]==' ')
            continue;
        else if(a[i]+p>= 'a'+26) //alfabetul englez are 26 litere
            a[i]+=p-26;          //puteam sa fac ceva sketchy cu 'z'-'a'+1 daca nu stiam numarul
        else
            a[i]+=p;
    }
    cout<<a;
}
int main()
{
    ex3();
    return 0;
}