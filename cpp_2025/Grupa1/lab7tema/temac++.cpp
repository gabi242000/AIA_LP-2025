#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++)
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
void sortareVector(int v[] , int n)
{
    quickSort(v, 0, n - 1);   
    cout << "Vectorul sortat este: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int cautareBinara(int v[], int n, int x)
{
    int st = 0;
    int dr = n - 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == x)
        {
            cout << "Elementul " << x << " se afla pe pozitia " << mij+1 << endl;
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
    cout << "Elementul nu a fost gasit!" << endl;
    return -1;
}

double gaussDeterminant(vector<vector<double>> matrice , int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrice[j][i] != 0)
            {
                float ratio = matrice[j][i] / matrice[i][i];
                for (int k = 0; k < n; k++)
                {
                    matrice[j][k] -= ratio * matrice[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (matrice[i][i] == 0)
        {
            cout << "Determinantul este 0!" << endl;
            return 0;
        }
    }
    double det = 1;
    for (int i = 0; i < n; i++)
    {
        det *= matrice[i][i];
    }
    return det;
}

bool esteInversabila(vector<vector<double>> matrice , int n)
{
    for (int i = 0; i < n; i++)
        if (matrice[i][i] == 0)
            return false;
    return true;
}

void criptare_vigenere(string text, string cheie)
{
    string text_criptat = "";
    for (int i = 0; i < text.length(); i++)
    {
        char c;
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int text_val = text[i] - 'A';
            int key_val = toupper(cheie[i % cheie.length()]) - 'A';
            c = ((text_val + key_val) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            int text_val = text[i] - 'a';
            int key_val = toupper(cheie[i % cheie.length()]) - 'A';
            c = ((text_val + key_val) % 26) + 'A';
        }
        else
        {
            cout << "Caracterele trebuie sa fie litere!" << endl;
            return;
        }
        text_criptat += c;
    }
    cout << "Textul criptat este: " << text_criptat << endl;
}
/// imi merge pt 2 3 cazuri sunt multumit 
void decriptare_vigenere(string text_criptat, string cheie)
{
    string text_decriptat = "";
    for (int i = 0; i < text_criptat.length(); i++)
    {
        if (text_criptat[i] >= 'a' && text_criptat[i] <= 'z')
        {
            int cipher_val = text_criptat[i] - 'a';
            int key_val = toupper(cheie[i % cheie.length()]) - 'A';
            int decrypted_val = (cipher_val - key_val + 26) % 26;
            char c = decrypted_val + 'A';
            text_decriptat += c;
        }
        if (text_criptat[i] >= 'A' && text_criptat[i] <= 'Z')
        {
            int cipher_val = text_criptat[i] - 'A';
            int key_val = toupper(cheie[i % cheie.length()]) - 'A';
            int decrypted_val = (cipher_val - key_val + 26) % 26;
            char c = decrypted_val + 'A';
            text_decriptat += c;
        }
        else if(isalpha(text_criptat[i]) == false)
        {
            cout << "Caracterele trebuie sa fie litere!" << endl;
            return;
        }
    }
    cout << "Textul decriptat este: " << text_decriptat << endl;
}

int main()
{
    int ex;
    while(true)
    {
        cout<<"Selecteaza exercitiul: ";
        cin>>ex;
        switch (ex)
        {
            case 1:
            {
                cout<<"Nr de elemente: ";
                int n;
                cin>>n;
                int v[n];
                for(int i=0; i<n; i++)
                {
                    cin>>v[i];
                }

                sortareVector(v , n);
                cout<<"Elementul cautat este:";
                int x;
                cin>>x;
                cautareBinara(v , n, x);
                break;
            }
            case 2:
            {
                cout<<"Nr de elemente: ";
                int n;
                cin>>n;
                vector<vector<double>> matrice(n, vector<double>(n));
                cout<<"Introduceti matricea: "<<endl;
                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        cin>>matrice[i][j];

                cout<<"Determinantul este: "<<gaussDeterminant(matrice , n)<<endl;
                if(esteInversabila(matrice , n))
                    cout<<"Matricea este inversabila!"<<endl;
                else
                    cout<<"Matricea nu este inversabila!"<<endl;
                break;
            }
            case 3:
            {
                string text, cheie;
                cout<<"Introduceti textul: ";
                cin.ignore();
                cin>>text;
                cout<<"Introduceti cheia: ";
                cin.ignore();
                cin>>cheie;
                criptare_vigenere(text, cheie);
                cout<<"Introduceti textul criptat: ";
                string text_criptat;
                cin.ignore();
                cin>>text_criptat;
                cout<<"Introduceti cheia: ";
                cin.ignore();
                cin>>cheie;
                decriptare_vigenere(text_criptat, cheie);
                break;
            }
            default:
                cout<<"Exercitiul nu exista!"<<endl;
                break;
        }
    }
    return 0;
}