#include <iostream>
using namespace std;

int main()
{
    int nota,ok=1;
    cout<<"Nota: ";
    cin>>nota;
    while(ok)
    {
        if(nota<=10 && nota>=9)
        {
            cout<<"Excelent";
            ok=0;
            
        }
        else if(nota<=5 && nota>=8)
        {
            cout<<"Satisfacator";
            ok=0;

        }
        else if(nota<5){
            cout<<"Mai incearca";
            ok=0;

        }
        else if(nota==0 || nota>10)
        {
            cout<<"Introdu o nota valabila"<<endl;
            cout<<"Nota: ";
            cin>>nota;
        }

    }
}
