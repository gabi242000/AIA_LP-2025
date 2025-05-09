#include <stdio.h>


int cmmdc(int a, int b){
    if(b==0) return a;
    else  return cmmdc(b,a%b);

}


int main(){
    int a,b,cmmd=0;

    scanf("%d %d",&a,&b);

    cmmd = cmmdc(a,b);

    printf("%d", cmmd);

   
}