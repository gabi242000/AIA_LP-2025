#include <iostream>
#include <cstring>
using namespace std;

char s[101], *cuv;
int p;

int main() {
    cout << "Introduceti un text: ";
    cin.getline(s, 101);

    cout << "Introduceti un numar: ";
    cin >> p;
    cuv = strtok(s, " ");

    cout << "Textul criptat cu ajutorul codului Cezar este: \n";
    while(cuv != NULL) {
        for(int i = 0; cuv[i] != '\0'; i++) {
            //in caz ca valoarea adunarii rezulta valoarea unui caracter care nu este litera
            if((islower(cuv[i]) && (int)cuv[i] + p > (int)'z') || (isupper(cuv[i]) && (int)cuv[i] + p > (int)'Z'))
              //la adunare scad cele 26 de litere, pentru a rezulta tot o litera
              cuv[i] = (char)((int)cuv[i] - 26 + p);
            else cuv[i] = (char)(cuv[i] + p);
        }
        cout << cuv << " ";
        cuv = strtok(NULL, " ");
    }

    return 0;
}