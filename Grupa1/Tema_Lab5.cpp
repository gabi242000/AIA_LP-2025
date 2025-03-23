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
    //doar principiul pe care merge si nu codul in caz ca nu stiati

    //tl;dr nu stiu cum sa rezolv si nu vreau sa bag chatgpt paste
    //as putea sa invat de pe pbinfo dar am de invatat si la alte materii
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
    
    return 0;
}