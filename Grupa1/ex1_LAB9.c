#include <stdio.h>

void invers(int n) {
    if(n==0)
        return;
    printf("%d", n % 10);       // Afișează ultima cifră
    invers(n / 10);             // Apelează recursiv pe restul numărului
}

int main() {
    int n;
    printf("Introdu un numar: ");
    scanf("%d", &n);

    if(n==0)
        printf("0");
    else
        invers(n);

    printf("\n");
    return 0;
}
