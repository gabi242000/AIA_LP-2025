#include <stdio.h>
int ogl = 0;
int func(int n) {
    if (n > 0) {
        ogl = ogl * 10 + n % 10;
        n = n / 10;
        return func(n);
    }
    else return ogl;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}
