#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[100];
    int p;

    cin.get(s,100);
    cin.get();
    cin>>p;

    for(int i=0;i<=strlen(s)-1;i++)
        if(isalpha(s[i])) s[i] = s[i]+p;

    cout<<"Sirul criptat este: "<<s;
}