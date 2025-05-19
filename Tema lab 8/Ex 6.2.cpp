#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;

    cout << "Introduceti primul sir: ";
    getline(cin, s1);  // Citim inclusiv spațiile

    cout << "Introduceti al doilea sir: ";
    getline(cin, s2);

    string concatenat = s1 + s2;  // Concatenare

    cout << "Concatenarea: " << concatenat << endl;

    return 0;
}
