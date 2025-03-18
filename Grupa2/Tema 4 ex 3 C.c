#include <stdio.h>

int main() {
    int N;
    printf("Introduceti N: ");
    scanf("%d", &N);
    
    if (N <= 0) {
        printf("Dimensiunea trebuie să fie pozitivă!\n");
        return 1;
    }
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int value;
            if (c >= r) {
                value = r + c + 1;
            } else {
                value = c + r + 1;
            }
            printf("%d ", value);
        }
        printf("\n");
    }
    
    return 0;
}
