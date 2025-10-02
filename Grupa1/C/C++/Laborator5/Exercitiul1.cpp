#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[200];
    cin.get(s,200);
    for(int i=0;i<strlen(s);i++)
        if(islower(s[i])) s[i]=toupper(s[i]);

    cout<<s;

}