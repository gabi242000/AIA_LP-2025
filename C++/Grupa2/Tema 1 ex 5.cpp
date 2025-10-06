#include <iostream>
using namespace std;
int main()
{
    int nota;
    cout<<"Introduceti o nota de la 1 la 10: ";
    cin>>nota;
    if(nota>=1 && nota <=10)
    {
        if(nota==10)
        cout<<"Exccelent!";
        else if(nota==9)
        cout<<"Minunat!";
        else if(nota==8)
        cout<<"Foarte bine!";
        else if(nota==7)
        cout<<"Se putea mai bine!";
        else if(nota==6)
        cout<<"Bine";
        else if(nota==5)
        cout<<"Satisfacator";
        else if(nota==4)
        cout<<"Mai invata";
        else if(nota==3)
        cout<<"Prost";
        else if(nota==2)
        cout<<"Execrabil";
        else cout<<"Renunta la facultate!";
    }
    else cout<<"Nota nu este valabila!";
    return 0;
}