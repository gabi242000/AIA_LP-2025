#include <iostream>

using namespace std;

void sortare(int v[100], int st,int dr){
    if(st<dr){
        int m = (st+dr)/2;
        int aux = v[st];
        v[st] = v[m];
        v[m]=aux;

        int i =st ,j=dr,d=0;

        while(i<j){
            if(v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
                d=1-d;
            }
            i+=d;
            j-=1-d;
        }
        sortare(v,st,i-1);
        sortare(v,i+1,dr);
    }
}


void cautareBinara(int v[100],int n, int x){
    int st=1, dr=n,poz=0;

    while(st<=dr && poz==0){
        int m = (st+dr)/2;
        if(v[m]=x) poz=m;
        if(v[x]<m) dr=m+1;
        else if(x>m) st=m-1;
    }

    if(poz!=0) cout<<"Numarul cautat se afla pe pozitia: "<<poz<<endl;
    else cout<<"Numarul nu se afla in vector"<<endl;
}

int main(){
    int v[100],n;

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    sortare(v,1,n);

    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";

    cout<<endl;
    cautareBinara(v,n,5);
    

    
}