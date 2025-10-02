#include <stdio.h>
#include <string.h>
#include <ctype.h>

int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = (low - 1);
    int j, temp;
    
    for (j = low; j <= high - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            if(i != j)
            {
                v[i] += v[j];
                v[j] = v[i] - v[j];
                v[i] -= v[j]; 
            }
        }
    }
    if(i + 1 != high)
    {
        v[i + 1] += v[high];
        v[high] = v[i + 1] - v[high];
        v[i + 1] -= v[high];
    }
    return (i + 1);
}

void quickSort(int v[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void sortareVector(int v[], int n)
{
    int i;
    quickSort(v, 0, n - 1);   
    printf("Vectorul sortat este: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int cautareBinara(int v[], int n, int x)
{
    int st = 0;
    int dr = n - 1;
    int mij;
    
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (v[mij] == x)
        {
            printf("Elementul %d se afla pe pozitia %d\n", x, mij+1);
            return mij;
        }
        else if (v[mij] < x)
        {
            st = mij + 1;
        }
        else
        {
            dr = mij - 1;
        }
    }
    printf("Elementul nu a fost gasit!\n");
    return -1;
}

double gaussDeterminant(double matrice[100][100], int n)
{
    int i, j, k;
    double ratio, det = 1.0;
    
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (matrice[j][i] != 0)
            {
                ratio = matrice[j][i] / matrice[i][i];
                for (k = 0; k < n; k++)
                {
                    matrice[j][k] -= ratio * matrice[i][k];
                }
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        if (matrice[i][i] == 0)
        {
            printf("Determinantul este 0!\n");
            return 0;
        }
    }
    
    for (i = 0; i < n; i++)
    {
        det *= matrice[i][i];
    }
    return det;
}

int esteInversabila(double matrice[100][100], int n)
{
    for (int i = 0; i < n; i++)
        if (matrice[i][i] == 0)
            return 0;
    return 1;
}

void criptare_vigenere(char text[], char cheie[])
{
    char text_criptat[100];
    int i, text_val, key_val;
    char c;
    
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text_val = text[i] - 'A';
            key_val = toupper(cheie[i % strlen(cheie)]) - 'A';
            c = ((text_val + key_val) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text_val = text[i] - 'a';
            key_val = toupper(cheie[i % strlen(cheie)]) - 'A';
            c = ((text_val + key_val) % 26) + 'A';
        }
        else
        {
            printf("Caracterele trebuie sa fie litere!\n");
            return;
        }
        text_criptat[i] = c;
    }
    text_criptat[i] = '\0';
    printf("Textul criptat este: %s\n", text_criptat);
}

void decriptare_vigenere(char text_criptat[], char cheie[])
{
    char text_decriptat[100];
    int i, cipher_val, key_val, decrypted_val;
    
    for (i = 0; i < strlen(text_criptat); i++)
    {
        if (text_criptat[i] >= 'a' && text_criptat[i] <= 'z')
        {
            cipher_val = text_criptat[i] - 'a';
            key_val = toupper(cheie[i % strlen(cheie)]) - 'A';
            decrypted_val = (cipher_val - key_val + 26) % 26;
            text_decriptat[i] = decrypted_val + 'A';
        }
        else if (text_criptat[i] >= 'A' && text_criptat[i] <= 'Z')
        {
            cipher_val = text_criptat[i] - 'A';
            key_val = toupper(cheie[i % strlen(cheie)]) - 'A';
            decrypted_val = (cipher_val - key_val + 26) % 26;
            text_decriptat[i] = decrypted_val + 'A';
        }
        else
        {
            printf("Caracterele trebuie sa fie litere!\n");
            return;
        }
    }
    text_decriptat[i] = '\0';
    printf("Textul decriptat este: %s\n", text_decriptat);
}

int main()
{
    int ex, i, j, n, x;
    
    while(1)
    {
        printf("Selecteaza exercitiul: ");
        scanf("%d", &ex);
        
        switch (ex)
        {
            case 1:
            {
                printf("Nr de elemente: ");
                int v[n];
                scanf("%d", &n);
                for(i=0; i<n; i++)
                {
                    scanf("%d", &v[i]);
                }
                sortareVector(v, n);
                printf("Elementul cautat este: ");
                scanf("%d", &x);
                cautareBinara(v, n, x);
                break;
            }
            case 2:
            {
                printf("Nr de elemente: ");
                scanf("%d", &n);
                double matrice[100][100];                
                printf("Introduceti matricea: \n");
                for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                scanf("%lf", &matrice[i][j]);
                
                printf("Determinantul este: %f\n", gaussDeterminant(matrice, n));
                if(esteInversabila(matrice, n))
                printf("Matricea este inversabila!\n");
                else
                printf("Matricea nu este inversabila!\n");
                break;
            }
            case 3:
            {
                char text[100], cheie[100], text_criptat[100];
                printf("Introduceti textul: ");
                scanf("%s", text);
                printf("Introduceti cheia: ");
                scanf("%s", cheie);
                criptare_vigenere(text, cheie);
                
                printf("Introduceti textul criptat: ");
                scanf("%s", text_criptat);
                printf("Introduceti cheia: ");
                scanf("%s", cheie);
                decriptare_vigenere(text_criptat, cheie);
                break;
            }
            default:
                printf("Exercitiul nu exista!\n");
                break;
        }
    }
    return 0;
}