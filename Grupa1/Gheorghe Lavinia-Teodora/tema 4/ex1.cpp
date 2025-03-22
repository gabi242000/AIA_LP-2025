#include <iostream>
#include <cstring>
using namespace std;

char s[256];

int main() {
    cout << "Introduceti un sir de caractere: ";
    cin.getline(s, 256);
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(isalpha(s[i]))
           s[i] = toupper(s[i]);
    }

    cout << "Sirul de caractere introdus a fost rescris doar cu majuscule: \n" << s;

    return 0;

}