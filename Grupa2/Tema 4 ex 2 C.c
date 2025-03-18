#include <stdio.h>

int main() {
    int N;
    printf("Introduceți numărul de elemente: ");
    scanf("%d", &N);

    int vec[N];
    printf("Introduceți elementele:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &vec[i]);
    }
    
    for (int i = 1; i < N; i++) {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j]) {
            vec[j - 1] ^= vec[j];
            vec[j] ^= vec[j - 1];
            vec[j - 1] ^= vec[j];
            j--;
        }
    }

    printf("Vectorul sortat fără duplicate: %d ", vec[0]);
    for (int i = 1; i < N; i++) {
        if (vec[i] != vec[i - 1]) {
            printf("%d ", vec[i]);
        }
    }
    printf("\n");
    
    return 0;
}
