#include <stdio.h>
int main() {
    char cuvant[26], c = ' ';
    int x,y;
    gets(cuvant);
    scanf("%d %d", &x, &y);
    c = cuvant[x];
    cuvant[x] = cuvant[y];
    cuvant[y] = c;
    printf("%s",cuvant);
    return 0;
}
