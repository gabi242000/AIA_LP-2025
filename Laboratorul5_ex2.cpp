#include <iostream>
#include <string.h>

using namespace std;

int main(){
    char cuv[20];
    int x, y;
    cout<<"Introdu un cuvant:";
    cin.getline(cuv,20);
    cout<<"Introdu doua poziti: ";
    cin>>x>>y;
    if(x<0 || x>strlen(cuv)&&y<0 || y>strlen(cuv)){
        cout<<"Pozitii invalide"<<endl;
        return 1;
    }
    swap(cuv[x],cuv[y]);
    cout<<"Noul cuvant este: "<<cuv;
    return 0;
    
}