#include <iostream>
#include <cstring>
using namespace std;

int verif_cons_voc(char s[]) {
    if(s[0] == 'z') {
        for(int i = 0; s[i] != '\0'; i += 2) {
            if(strchr("aeiou", s[i]) != NULL)
              return 0;
        }
        for(int i = 1; s[i] != '\0'; i += 2)
           if(strchr("aeiou", s[i]) == NULL)
             return 0;
    }
    else return 0;

    return 1;
}

char s[101];

int main() {
    cout << "Introduceti un cuvant: ";
    cin >> s;
    if(verif_cons_voc(s) == 1 && strlen(s) % 2 == 0)
       cout << "Cuvantul este frumos!";
    else cout << "Cuvantul NU este frumos!";

    return 0;
}