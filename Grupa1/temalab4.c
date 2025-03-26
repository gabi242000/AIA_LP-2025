#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100 //am folosit define pt ca avem erori legate de dimensiunea matricelor
//acum programul va verifica daca N depaseste MAX_N si va opri executia

//Problema 1
void randul_care_are_suma_elem_max(int N, int mat[MAX_N][MAX_N]){
    int sumaMax = -1;
    int randIndex = -1;
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += mat[i][j];
        }
        if (suma > sumaMax) {
            sumaMax = suma;
            randIndex = i;
        }
    }
    printf("Randul cu suma maxima: %d\n", randIndex+1);//sa afiseze randul corect pt ca eu folosesc indexarea de la zero, dar utilizatorul cand verifica numara de la 1
    printf("Suma: %d\n", sumaMax);
}

//Scrie un program care citeste un vector cu N elemente: sorteaza,
//elimina elem duplicate, afiseaza vectorul final
void sortare_eliminare_afisare(int N, int vector[MAX_N]){
    //prima data sortam vectorul
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vector[i] > vector[j]) {
                int temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }

    //eliminam elementele duplicate, apoi le afisam
    printf("Vectorul final este: ");
    printf("%d", vector[0]); // Afișăm primul element
    for (int i = 1; i < N; i++) {
        if (vector[i] != vector[i - 1]) {
            printf(" %d", vector[i]); // Afișăm elementele ne-duplicate
        }
    }
    printf("\n");

}

//Generare matrice simetrica
void generareMatrice(int N, int mat[MAX_N][MAX_N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i <= j) {
                mat[i][j] = i + j + 1;
            } else {
                mat[i][j] = mat[j][i];
            }
            printf("%d ", mat[i][j]); // Adăugăm un spațiu între elemente
        }
        printf("\n");
    }
}

//Problema 4: Găsirea unui element vârf într-o matrice N × N
void gaseste_vrf(int N, int mat[MAX_N][MAX_N]) {
    for (int i = 1; i < N - 1; i++) { // începe de la 1 și se oprește înainte de N-1 pentru a evita colțurile
        for (int j = 1; j < N - 1; j++) {
            int element = mat[i][j];
            if (element > mat[i-1][j] && element > mat[i+1][j] && element > mat[i][j-1] && element > mat[i][j+1]) {
                printf("Elementul vrf gasit este: %d, la pozitia (%d, %d)\n", element, i, j);
                return; // Stop searching after finding the first peak
            }
        }
    }
    printf("Nu exista elemente vrf in matrice.\n");
}

int main() {
    int N;
    printf("Introduceti dimensiunea matricei/vectorului: ");
    scanf("%d", &N);

    // Problema 1
    int matrice[MAX_N][MAX_N];
    printf("Introduceti matricea %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
    randul_care_are_suma_elem_max(N, matrice);

    // Problema 2
    int vector[MAX_N];
    printf("Introduceti vectorul cu %d elemente:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vector[i]);
    }
    sortare_eliminare_afisare(N, vector);

    // Problema 3
    int mat[MAX_N][MAX_N];
    printf("Matricea generata este:\n");
    generareMatrice(N, mat);

    // Problema 4
    printf("Introduceti matricea pentru a cauta un element vrf:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    gaseste_vrf(N, mat);

    return 0;
}
