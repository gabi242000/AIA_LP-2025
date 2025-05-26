#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int DIMENSIUNE_TABLA = 8;

enum Piesa {
    GOL = 0,
    ROSU = 1,
    NEGRU = 2,
    REGE_ROSU = 3,
    REGE_NEGRU = 4
};

vector<vector<int>> tabla(DIMENSIUNE_TABLA, vector<int>(DIMENSIUNE_TABLA, GOL));

bool esteRege(int piesa) {
    return piesa == REGE_ROSU || piesa == REGE_NEGRU;
}

bool esteAdversar(int jucator, int piesa) {
    if (jucator == ROSU) return piesa == NEGRU || piesa == REGE_NEGRU;
    return piesa == ROSU || piesa == REGE_ROSU;
}

bool esteAceeasiPiesa(int jucator, int piesa) {
    if (jucator == ROSU) return piesa == ROSU || piesa == REGE_ROSU;
    return piesa == NEGRU || piesa == REGE_NEGRU;
}

void initializeazaTabla() {
    for (int linie = 0; linie < DIMENSIUNE_TABLA; ++linie) {
        for (int coloana = 0; coloana < DIMENSIUNE_TABLA; ++coloana) {
            if ((linie + coloana) % 2 == 1) {
                if (linie < 3)
                    tabla[linie][coloana] = NEGRU;
                else if (linie > 4)
                    tabla[linie][coloana] = ROSU;
            }
        }
    }
}

void afiseazaTabla() {
    cout << "  ";
    for (int coloana = 0; coloana < DIMENSIUNE_TABLA; ++coloana)
        cout << coloana << " ";
    cout << "\n";

    for (int linie = 0; linie < DIMENSIUNE_TABLA; ++linie) {
        cout << linie << " ";
        for (int coloana = 0; coloana < DIMENSIUNE_TABLA; ++coloana) {
            char simbol = '.';
            switch (tabla[linie][coloana]) {
                case ROSU: simbol = 'r'; break;
                case NEGRU: simbol = 'n'; break;
                case REGE_ROSU: simbol = 'R'; break;
                case REGE_NEGRU: simbol = 'N'; break;
            }
            cout << simbol << " ";
        }
        cout << "\n";
    }
}

bool esteMutareSimplaValida(int jucator, int deLaLinie, int deLaColoana, int laLinie, int laColoana) {
    if (laLinie < 0 || laLinie >= DIMENSIUNE_TABLA || laColoana < 0 || laColoana >= DIMENSIUNE_TABLA) return false;
    if (tabla[laLinie][laColoana] != GOL) return false;

    int piesa = tabla[deLaLinie][deLaColoana];
    int diferentaLinie = laLinie - deLaLinie;
    int diferentaColoana = abs(laColoana - deLaColoana);

    if (diferentaColoana != 1) return false;

    if (esteRege(piesa)) return abs(diferentaLinie) == 1;

    return (jucator == ROSU && diferentaLinie == -1) || (jucator == NEGRU && diferentaLinie == 1);
}

bool esteCapturaValida(int jucator, int deLaLinie, int deLaColoana, int laLinie, int laColoana) {
    if (laLinie < 0 || laLinie >= DIMENSIUNE_TABLA || laColoana < 0 || laColoana >= DIMENSIUNE_TABLA) return false;
    if (tabla[laLinie][laColoana] != GOL) return false;

    int piesa = tabla[deLaLinie][deLaColoana];
    int diferentaLinie = laLinie - deLaLinie;
    int diferentaColoana = laColoana - deLaColoana;

    if (abs(diferentaLinie) != 2 || abs(diferentaColoana) != 2) return false;

    int linieMijloc = (deLaLinie + laLinie) / 2;
    int coloanaMijloc = (deLaColoana + laColoana) / 2;

    if (!esteAdversar(jucator, tabla[linieMijloc][coloanaMijloc])) return false;

    if (esteRege(piesa)) return true;

    return (jucator == ROSU && diferentaLinie == -2) || (jucator == NEGRU && diferentaLinie == 2);
}

bool poateCaptura(int jucator, int linie, int coloana) {
    int dL[] = {-2, -2, 2, 2};
    int dC[] = {-2, 2, -2, 2};
    for (int i = 0; i < 4; ++i) {
        int nl = linie + dL[i];
        int nc = coloana + dC[i];
        if (esteCapturaValida(jucator, linie, coloana, nl, nc))
            return true;
    }
    return false;
}

void promoveazaDacaEsteNecesar(int linie, int coloana) {
    if (tabla[linie][coloana] == ROSU && linie == 0)
        tabla[linie][coloana] = REGE_ROSU;
    else if (tabla[linie][coloana] == NEGRU && linie == DIMENSIUNE_TABLA - 1)
        tabla[linie][coloana] = REGE_NEGRU;
}

void executaMutare(int jucator, int deLaLinie, int deLaColoana, int laLinie, int laColoana) {
    int piesa = tabla[deLaLinie][deLaColoana];

    if (abs(laLinie - deLaLinie) == 2) {
        int linieMijloc = (deLaLinie + laLinie) / 2;
        int coloanaMijloc = (deLaColoana + laColoana) / 2;
        tabla[linieMijloc][coloanaMijloc] = GOL;
    }

    tabla[laLinie][laColoana] = piesa;
    tabla[deLaLinie][deLaColoana] = GOL;

    promoveazaDacaEsteNecesar(laLinie, laColoana);

    if (abs(laLinie - deLaLinie) == 2) {
        while (poateCaptura(jucator, laLinie, laColoana)) {
            afiseazaTabla();
            cout << "Mai poti face un salt! Introdu pozitia (la_linie la_coloana): ";
            int linieUrm, coloanaUrm;
            cin >> linieUrm >> coloanaUrm;

            if (esteCapturaValida(jucator, laLinie, laColoana, linieUrm, coloanaUrm)) {
                executaMutare(jucator, laLinie, laColoana, linieUrm, coloanaUrm);
                laLinie = linieUrm;
                laColoana = coloanaUrm;
            } else {
                cout << "Mutare invalida.\n";
                break;
            }
        }
    }
}

bool areMutari(int jucator) {
    for (int linie = 0; linie < DIMENSIUNE_TABLA; ++linie) {
        for (int coloana = 0; coloana < DIMENSIUNE_TABLA; ++coloana) {
            if (esteAceeasiPiesa(jucator, tabla[linie][coloana])) {
                int dL[] = {-1, -1, 1, 1};
                int dC[] = {-1, 1, -1, 1};
                for (int i = 0; i < 4; ++i) {
                    int nl = linie + dL[i];
                    int nc = coloana + dC[i];
                    if (esteMutareSimplaValida(jucator, linie, coloana, nl, nc)) return true;
                    if (esteCapturaValida(jucator, linie, coloana, linie + 2 * dL[i], coloana + 2 * dC[i])) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    initializeazaTabla();
    int jucatorCurent = ROSU;

    while (true) {
        afiseazaTabla();
        if (!areMutari(jucatorCurent)) {
            cout << ((jucatorCurent == ROSU) ? "Negrul" : "Rosul") << " a castigat!\n";
            break;
        }

        cout << "Este randul jucatorului " << ((jucatorCurent == ROSU) ? "Rosu" : "Negru") << ".\n";
        int deLaLinie, deLaColoana, laLinie, laColoana;
        cout << "Introdu mutarea (de_la_linie de_la_coloana la_linie la_coloana): ";
        cin >> deLaLinie >> deLaColoana >> laLinie >> laColoana;

        if (!esteAceeasiPiesa(jucatorCurent, tabla[deLaLinie][deLaColoana])) {
            cout << "Selectia piesei invalida.\n";
            continue;
        }

        if (esteMutareSimplaValida(jucatorCurent, deLaLinie, deLaColoana, laLinie, laColoana) ||
            esteCapturaValida(jucatorCurent, deLaLinie, deLaColoana, laLinie, laColoana)) {
            executaMutare(jucatorCurent, deLaLinie, deLaColoana, laLinie, laColoana);
            jucatorCurent = (jucatorCurent == ROSU) ? NEGRU : ROSU;
        } else {
            cout << "Mutare invalida.\n";
        }
    }

    return 0;
}
