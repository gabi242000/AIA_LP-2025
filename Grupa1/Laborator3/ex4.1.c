#include <stdio.h>
int main() {
    int numar;
    printf("Introdu un numar: ");
    scanf("%d", &numar);
    for(int i=2; i <= numar; i+=2) {
        printf("%d ", i);
    }
return 0;
}