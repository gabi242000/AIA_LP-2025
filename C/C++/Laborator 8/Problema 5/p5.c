/**
5. Creează un program care alocă dinamic un vector de N numere întregi, citește valorile, apoi 
creează un al doilea vector (tot alocat dinamic) care conține aceleași elemente în ordine 
inversă. Afișează ambii vectori. 
**/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *v1, *v2;

    printf ("Introdu numarul de elemente ale vectorului: ");
    scanf ("%d", &n);

    v1 = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        printf("Elementul %d: ", i);
        scanf("%d", &v1[i]);
    }

    v2 = (int*)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--){
        v2[n - 1 - i] = v1[i];
    }

    for (int i = 0; i < n; i++){
        printf("v1[%d]: %d\n",i ,v1[i]);
    }
    for (int i = 0; i < n; i++){
        printf("v2[%d]: %d\n",i ,v2[i]);
    }

    free (v1);
    free (v2);
    return 0;

}