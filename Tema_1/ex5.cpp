//ex5
#include <iostream>
using namespace std;
int main(){
    int nota;
    cout<<"Introduceti o nota de la 1 la 10:";
    cin>>nota;
    switch(nota){
        case 10:
            cout<<"Excelent!"<<endl;
            break;
        case 9:
            cout<<"Foarte bine!"<<endl;
            break;
        case 8:
            cout<<"Bine1"<<endl;
            break;
        case 7:
            cout<<"Acceptabil1"<<endl;
            break;
        case 6:
            cout<<"Satisfacator!"<<endl;
            break;
        case 5:
            cout<<"Suficient!"<<endl;
            break;
        case 4:
        case 3:
        case 2:
        case 1:
            cout<<"Insuficient!"<<endl;
            break;
        default:
            cout<<"Ai introdus o nota invalida.Mai incearca!!!"<<endl;
            break;
    }
    return 0;
}