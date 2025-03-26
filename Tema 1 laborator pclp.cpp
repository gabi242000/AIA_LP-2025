//Exercitiul 1:
#include <iostream>
using namespace std;

int main()
{
    int x;
    cout<<"Introduceti nota:";
    cin>>x;
    if(x>=1&&x<=4)
        cout<<"Nesatisfacator!";
    else if(x>=5&&x<=7)
        cout<<"Satisfacator!";
    else if(x>=8&&x<=10)
        cout<<"Excelent!";
    return 0;
}

//Exercitiul 2:
#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout<<"Pret produs:";
    cin>>x;
    cout<<"Codul de reducere: Cod ";
    cin>>y;
    if(y==1)
        cout<<x-(x*10/100);
    if(y==2)
        cout<<x-(x*20/100);
    if(y==3)
        cout<<x-(x*30/100);
    if(y>=4)
        cout<<"Codul de reducere este invalid!";
    return 0;
}

//Exercitiul 3:
#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout<<"Salariul brut:";
    cin>>x;
    cout<<"Salariu pentru angajat:Cod ";
    cin>>y;
    if(y==1)
        cout<<x-(x*25/100);
    if(y==2)
        cout<<x-(x*10/100);
    if(y==3)
        cout<<x-(x*5/100);
    else if(y!=1&&y!=2&&y!=3)
        cout<<"Codul introdus este invalid!";
    return 0;
}