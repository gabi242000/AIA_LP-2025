#include <stdio.h>

int simetrica(int n, int a[200][200])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                printf("Matrice NEsimetrica\n");
                return 0;
            }
        }
    }
    printf("Matrice simetrica\n");


}

int transpusa(int a, int b[200][200], int aux)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++){
            aux = b[i][j]; 
            b[i][j] = b[j][i]; 
            b[j][i] = aux;
        }
    }
    
    printf("Transpusa: \n");

    for(int i = 0; i < a; i++){
        for(int j = 0; j< a; j++){
            printf("%d ", b[j][i]);
            
        }
        printf("\n");
    }
}

int magic(int a, int b[200][200])
{
    int suma1 = 0, suma2 = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            suma1 += b[i][i];
            suma2 += b[i][a - 1 - i];
        }
    }

    if(suma1 == suma2){
        printf("Matrice partial magica");
    }else{
        printf("Matrice obisnuita");
    }
}

int main()
{
    int m; 
    int v[200][200];

    printf("introdu dimensiunile matricei: ");
    scanf("%d", &m);

    printf("introdu elementele matricei: ");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++)
            scanf("%d", &v[i][j]);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", v[i][j]);
            printf("\n");
    }

    simetrica(3, v);
    transpusa(3, v, 0);
    magic(3, v);

    return 0;
}