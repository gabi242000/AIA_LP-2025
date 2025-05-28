#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

string numeOptiune(int alegere) {
    switch (alegere) {
        case 1: return "Piatra";
        case 2: return "Hartie";
        case 3: return "Foarfeca";
        default: return "Necunoscut";
    }
}

int alegereCalculator() {
    return rand() % 3 + 1;
}

void curataEcran() {
    cout << string(50, '\n');
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int scorJucator = 0, scorCalculator = 0;
    char joacaDinNou;

    cout << "===== Bine ai venit la jocul PIATRA - HARTIE - FOARFECA! =====\n";
    cout << "==============================================================\n";

    do {
        int alegereJucator = 0;


        while (true) {
            cout << "\n Alege: \n";
            cout << " 1. Piatra\n 2. Hartie\n 3. Foarfeca\n";
            cout << "Introdu optiunea ta: ";
            cin >> alegereJucator;

            if (cin.fail() || alegereJucator < 1 || alegereJucator > 3) {
                cout << "EROARE!!!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        int alegerePC = alegereCalculator();

        cout << "\nAlegerea ta: " << numeOptiune(alegereJucator) << endl;
        cout << "Alegere comp " << numeOptiune(alegerePC) << endl;

        if (alegereJucator == alegerePC) {
            cout << "EGALITATE\n ";
        } else if ((alegereJucator == 1 && alegerePC == 3) ||
                   (alegereJucator == 2 && alegerePC == 1) ||
                   (alegereJucator == 3 && alegerePC == 2)) {
            cout << "AI CASTIGAT \n";
            scorJucator++;
        } else {
            cout << "DA BANII! SI MAI INCEARCA O DATA \n";
            scorCalculator++;
        }

        cout << "\n Scor curent: \n";
        cout << "Tu: " << scorJucator << " | Cal: " << scorCalculator << "\n";

        cout << "\n Mai bagi o fisa? (da/nu): \n";
cout << "==============================================================\n";
        cin >> joacaDinNou;

        while (joacaDinNou != 'd' && joacaDinNou != 'D' &&
               joacaDinNou != 'n' && joacaDinNou != 'N') {
            cout << "Raspunde cu 'd' pentru da sau 'n' pentru nu: ";
            cin >> joacaDinNou;
        }

        curataEcran();
cout << "==============================================================\n";
    } while (joacaDinNou == 'd' || joacaDinNou == 'D');


    cout << "Joc terminat! \n";
    cout << "Scor final: Tu " << scorJucator << " - " << scorCalculator << " Cal \n";

    if (scorJucator > scorCalculator) {
        cout << "Ai castigat razboiul! \n";
    } else if (scorJucator < scorCalculator) {
        cout << "Calculatorul a castigat \n";
    } else {
        cout << "La fel de buni amandoi :/ \n";
    }
cout << "==============================================================\n";


    return 0;
}
