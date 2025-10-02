#include <iostream>

using namespace std;

int main(){
    int nota;
    cout<<"Introdu o nota de la 1 la 10:";
    cin>>nota;
    
    switch (nota)
    {
    case 1:
        cout<<"De ce copiezi ma?";
            break;
    case 2:
        cout<<"N-ai invatat nimic!";
             break;
    case 3:
        cout<<"Foarte slab";
             break;
    case 4:
        cout<<"Slab";
                break;

    case 5:
        cout<<"Satisfacator";
                break;
    case 6:
        cout<<"Satisfacator";
            break;
    case 7:
        cout<<"Binisor";
            break;
    case 8:
        cout<<"Bine";
            break;
    case 9:
        cout<<"Foarte bine";
            break;
    case 10:
        cout<<"Excelent";
            break;

    
    default:
        cout<<"Valoarea introdusa nu este valida";
            break;
    }
}