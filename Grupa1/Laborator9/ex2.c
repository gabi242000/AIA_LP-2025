#include <stdio.h>
int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    int c;
    if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
    return cmmdc(a-b,b);
}
int main()
{
    int a,b;
    printf("introduceti 2 nr: ");
    scanf("%d %d", &a,&b);
    printf("cmmdc al celor 2 nr este: %d", cmmdc(a,b));
    return 0;
}
