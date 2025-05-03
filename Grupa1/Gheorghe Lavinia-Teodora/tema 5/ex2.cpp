#include <iostream>
#include <cstring>
using namespace std;

char s[101];
int p;

void cripteaza(char s[], int key) {
    char *cuv, cezar[101] = "";
    cuv = strtok(s, " ");

    cout << "Textul criptat cu ajutorul codului Cezar este:" << "\n";
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            if((islower(cuv[i]) && (int)cuv[i] + key > (int)'z') || (isupper(cuv[i]) && (int)cuv[i] + key > (int)'Z'))
                 cuv[i] = (char)((int)cuv[i] - 26 + key);
            else cuv[i] = (char)((int)cuv[i] + key);
        }
        cout << cuv << " ";
        strcat(cezar, cuv);
        strcat(cezar, " ");
        cuv = strtok(NULL, " ");
    }
    strcpy(s, cezar);
}

void decripteaza(char s[], int key) {
    char *cuv, decript[101] = "";
    cuv = strtok(s, " ");
    cout << "Verificare - textul decriptat este:" << "\n";
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            if((islower(cuv[i]) && (int)cuv[i] + key < (int)'a') || (isupper(cuv[i]) && (int)cuv[i] + key < (int)'A'))
               cuv[i] = (char)((int)cuv[i] + 26 - key);
            else cuv[i] = (char)((int)cuv[i] - key);
        }
        cout << cuv << " ";
        cuv = strtok(NULL, " ");
    }


}

int main() {
    cout << "Introduceti un text:" << "\n";
    cin.getline(s, 101);
    cout << "Introduceti un numar: ";
    cin >> p;
    cripteaza(s, p);
    cout << "\n";
    decripteaza(s, p);

    return 0;
}