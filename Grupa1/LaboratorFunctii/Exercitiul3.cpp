#include <iostream>
#include <cstring>

using namespace std;

void criptare(char s[200],int key){
    char circular[54];
    int nrlitere = 0;
    int cnt=0;
    for(char x = 'Z';nrlitere <key; x--,nrlitere++){
        circular[cnt] = x;
        cnt++;
    }
    nrlitere = 0;
    for(char x='z';nrlitere<key;x--,nrlitere++){
        circular[cnt] =x;
        cnt++;
    }
    for(int i=0;i<strlen(s);i++)
        if(isalpha(s[i])) 
            if(strchr(circular,s[i])) s[i] = s[i]-(26-key);
            else s[i] = s[i]+key;
}

void decriptare(char s[200],int key){
    char circular[54];
    int nrlitere = 0;
    int cnt=0;
    for(char x = 'A';nrlitere <key; x++,nrlitere++){
        circular[cnt] = x;
        cnt++;
    }
    nrlitere = 0;
    for(char x='a';nrlitere<key;x++,nrlitere++){
        circular[cnt] =x;
        cnt++;
    }
    for(int i=0;i<strlen(s);i++)
        if(isalpha(s[i]))
            if(strchr(circular,s[i])) s[i]=s[i]+(26-key);
            else s[i]=s[i]-key;

}


int main(){
    char s[200]; int  key;
    cin.get(s,200);
    cin>>key;
    cout<<s<<endl;
    criptare(s,key);

    cout<<s<<endl;

    decriptare(s,key);

    cout<<s<<endl;
    

}