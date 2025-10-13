/**
4. Scrie un program care citește N numere întregi de la tastatură, stocate într-un vector alocat 
dinamic. Programul calculează media aritmetică a elementelor, apoi creează un nou vector 
(tot dinamic) care conține doar valorile mai mari sau egale cu media. Afișează acest nou 
vector. 
**/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *v, *v1, suma = 0, medie, k = 0;
    printf ("Introdu numarul de elemente ale vectorului: ");
    scanf ("%d", &n);
    v = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++){
        suma += v[i];
    }

    medie = suma/n;
    v1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        if (v[i] >= medie){
            v1[k] = v[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++){
        printf("v1[%d]: %d\n",i ,v[i]);
    }

    free (v);
    free (v1);
    return 0;

}