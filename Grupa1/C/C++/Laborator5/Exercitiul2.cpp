#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[100],aux;
    int x,y;

    cout<<"Introdu un cuvant:";
    cin>>s;

    cout<<"Introdu doua pozitii"<<endl;

    while(cin>>x>>y){
        if(x>=0 && x<=strlen(s)-1 && y>=0 && x<=strlen(s)-1) break;
        else cout<<"Pozitiile date nu sunt valide"<<endl;
    }

    aux = s[x];
    s[x]=s[y];
    s[y]=aux;
    
    cout<<"Cuvantul rezultat este: "<<s;
    
}