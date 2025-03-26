#include <stdio.h>
int main()
{
    char s[25],a;
    int x,y;
    scanf("%s", s);
    scanf("%d %d", &x, &y);
    a=s[x];
    s[x]=s[y];
    s[y]=a;
    printf("%s", s);
    return 0;
}
