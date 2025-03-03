#include <iostream>
using namespace std;

int main()
{
	int nota;

	while (true) {
		cout << "Introduceti nota: ";
		cin >> nota;

		if (nota <= 10 && nota >= 1) {
			if (nota >= 7)
				cout << "Excelent";
			else if (nota >= 5)
				cout << "Satisfacator";
			else cout << "Insuficient";
			break;
		}
		else cout << "Nota introdusa nu este valida." << endl;
	}

	return 0;
}
