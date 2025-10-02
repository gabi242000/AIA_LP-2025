#include <iostream>

using namespace std;
int cmmdc(int a, int b){
    if(b==0) return a;
    else  return cmmdc(b,a%b);

}


int main(){
    int a,b,cmmd=0;

    cin>>a>>b;

    cmmd = cmmdc(a,b);

    cout<<cmmd;

   
}