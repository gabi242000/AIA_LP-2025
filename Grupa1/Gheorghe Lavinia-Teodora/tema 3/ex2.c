#include <stdio.h>

int main() {
    int N;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &N);

    int v[N], aux = 0;
    printf("Introduceti elementele vectorului: ");

    for(int i = 0; i < N; i++)
       scanf("%d", &v[i]);

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
              
            }
        }
    }
    
    for(int i = 0; i < N - 1; i++) {
        if(v[i] == v[i + 1]) {
            for(int k = i; k < N - 1; k++)
               v[k] = v[k + 1];
            N --;
            i --;
        }
    }

    printf("Vectorul ordonat crescator si din care s-au eliminat dublurile arata astfel: \n");
    for(int i = 0; i < N; i++)
        printf("%d ", v[i]);
       
    return 0;
    
}