#include <iostream>
using namespace std;
int main(){
    int x;
    cout<<"Introduceti nota: ";
    cin>>x;
    if(x>0 && x<=3){
        cout<<"Insuficient";
    }else if(x>=4 && x<=6){
        cout<<"Suficient";
    }else if(x>6 && x<9){
        cout<<"Bine";
    }else if(x>8 && x<=10){
        cout<<"Foarte bine!!!";
    }else cout<<"Numarul introdus nu este intre 1 si 10";
    return 0;
}
