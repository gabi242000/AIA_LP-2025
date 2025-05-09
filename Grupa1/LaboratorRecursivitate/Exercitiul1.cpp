#include <iostream>

using namespace std;
int p=1;

int invers(int n){
    if(n<10) return n;
    else {
        p/=10;
        return n%10*p + invers(n/10);
    }

}

int main(){
    int n,n_invers,co;

    cin>>n;
    co=n;
    while(co!=0){
        co/=10; p*=10;
    }

    n_invers= invers(n);

    cout<<n_invers;
    


}