#include <stdio.h>
//exercitiu 4.1
int main() {
    int N, i;
    printf("Introduce-ti un numar: ");
    scanf("%d", &N);

    for(i=0; i<=N; i++){
        if(i%2==0){
            printf("Numerele pare pana la %d sunt: %d\n", N, i);
    }
}
 //exercitiul 4.2
int f0 = 0, f1 = 1, fn;

    
printf("Primele %d numere Fibonacci: ", N);

for (int i = 0; i < N; i++) {
    if (i == 0) {
        printf("%d ", f0);
    } else if (i == 1) {
        printf("%d ", f1);
    } else {
        fn = f0 + f1; 
        printf("%d ", fn);
        f0 = f1; 
        f1 = fn;
    }
}

printf("\n");

//exercitiul 4.3
printf("Introduceți numărul de rânduri: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            printf(" ");
        }

        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*\n");
        }
    }
}