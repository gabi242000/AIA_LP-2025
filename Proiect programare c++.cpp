#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int DIMENSIUNE = 5;
const int NR_MINI = 3;

char tablaAfisata[DIMENSIUNE][DIMENSIUNE];
int tablaCuMine[DIMENSIUNE][DIMENSIUNE];


void initializareTabele() {
    for (int linie = 0; linie < DIMENSIUNE; linie++)
        for (int coloana = 0; coloana < DIMENSIUNE; coloana++) {
            tablaAfisata[linie][coloana] = '-';
            tablaCuMine[linie][coloana] = 0;
        }
}


void plaseazaMine() {
    int minePlasate = 0;
    while (minePlasate < NR_MINI) {
        int linie = rand() % DIMENSIUNE;
        int coloana = rand() % DIMENSIUNE;
        if (tablaCuMine[linie][coloana] == 0) {
            tablaCuMine[linie][coloana] = 1;
            minePlasate++;
        }
    }
}


void afiseazaTabla() {
    cout << "   ";
    for (int i = 0; i < DIMENSIUNE; i++)
        cout << i << " ";
    cout << endl;

    for (int linie = 0; linie < DIMENSIUNE; linie++) {
        cout << linie << "  ";
        for (int coloana = 0; coloana < DIMENSIUNE; coloana++)
            cout << tablaAfisata[linie][coloana] << " ";
        cout << endl;
    }
}


void afiseazaMine() {
    cout << "\nTabla cu mine:\n";
    cout << "   ";
    for (int i = 0; i < DIMENSIUNE; i++)
        cout << i << " ";
    cout << endl;

    for (int linie = 0; linie < DIMENSIUNE; linie++) {
        cout << linie << "  ";
        for (int coloana = 0; coloana < DIMENSIUNE; coloana++)
            cout << (tablaCuMine[linie][coloana] ? '*' : '.') << " ";
        cout << endl;
    }
}

int main() {
    srand(time(0));
    char alegere;

    do {
        initializareTabele();
        plaseazaMine();

        int mutari = 0;
        bool inViata = true;

        while (inViata && mutari < DIMENSIUNE * DIMENSIUNE - NR_MINI) {
            afiseazaTabla();

            int linie, coloana;
            cout << "Alege o celulă (linie și coloană): ";
            cin >> linie >> coloana;

            if (linie < 0 || linie >= DIMENSIUNE || coloana < 0 || coloana >= DIMENSIUNE) {
                cout << "Coordonate invalide!\n";
                continue;
            }

            if (tablaCuMine[linie][coloana] == 1) {
                cout << "Ai călcat pe o mină! GAME OVER.\n";
                inViata = false;
            } else {
                int mineInApropiere = 0;
                for (int i = linie - 1; i <= linie + 1; i++)
                    for (int j = coloana - 1; j <= coloana + 1; j++)
                        if (i >= 0 && i < DIMENSIUNE && j >= 0 && j < DIMENSIUNE)
                            mineInApropiere += tablaCuMine[i][j];

                tablaAfisata[linie][coloana] = '0' + mineInApropiere;
                mutari++;
            }
        }

        if (mutari == DIMENSIUNE * DIMENSIUNE - NR_MINI)
            cout << "Felicitări! Ai câștigat!\n";

        afiseazaMine();

        cout << "\nVrei să joci din nou? (d/n): ";
        cin >> alegere;
    } while (alegere == 'd' || alegere == 'D');

    cout << "La revedere!\n";
    return 0;
}
