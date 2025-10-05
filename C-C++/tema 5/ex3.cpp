#include <iostream>
#include <cstring>
using namespace std;
void cripteaza(char s[], int key)
{
    for (int i = 0; i <= strlen(s) - 1; i++)
        if (s[i] != ' ')
            s[i] = s[i] + key;

    cout << "Sirul codat este : ";
    cout << s;
}

void decripteaza(char s[], int key)
{
    for (int i = 0; i <= strlen(s) - 1; i++)
        if (s[i] != ' ')
            s[i] = s[i] - key;

    cout << "Sirul decodat este : ";
    cout << s;
}

int main()
{
    int i, key;
    char s[100], s2[100];
    cout << "Introduceti propozitia : ";
    cin.getline(s, 100);
    cout << "Key : ";
    cin >> key;
    cripteaza(s, key);
    cout << endl;
    strcpy(s2, s);
    decripteaza(s2, key);
    return 0;
}
