#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void afisare_spanzuratoare(int vieti) 
{
    const vector<string> etape = 
    {
        "  _______\n |       |\n |        \n |        \n |        \n_|_\n",
        "  _______\n |       |\n |       O\n |        \n |        \n_|_\n",
        "  _______\n |       |\n |       O\n |       |\n |        \n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\n |        \n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\\\n |        \n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\\\n |      / \n_|_\n",
        "  _______\n |       |\n |       O\n |      /|\\\n |      / \\\n_|_\n"
    };
    cout << etape[6 - vieti] << endl;
}

void afisare_cuvant( const string &cuvant, const vector<char> &ghicit ) 
{
    for (char c : cuvant) 
    {
        if ( find ( ghicit.begin(), ghicit.end(), c ) != ghicit.end() ) 
        {
            cout << c <<" ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool cuvant_ghicit( const string &cuvant, const vector<char> &ghicit )
{
    for (char c : cuvant) {
        if ( find ( ghicit.begin(), ghicit.end(), c ) == ghicit.end() )
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    srand(time(0));

    vector<string> lista_cuvinte = {"proiectant", "programare", "rinocer", "carte", "romania", "ploaie", "strugure",
        "albina", "restaurant", "adunare", "mancare", "perpendicular", "paralelipiped", "creatie", "floare", "carte",
        "munte", "pian", "lumină", "călătorie", "vânt", "zâmbet", "stea", "oglindă", "pădure", "râu", "cafenea", "oraș",
        "zebră", "umbre", "creion", "bibliotecă", "castel", "muzică", "fruct", "cald", "frig", "păianjen", "val", "pisică",
        "pisică", "nori", "clopot", "fotografie", "oglindă", "lanternă", "pasăre", "șoarece", "oglindă", "cer", "lup", "răsărit", 
        "valiză", "fereastră"};

    string cuvant_secret = lista_cuvinte[rand() % lista_cuvinte.size()];
    vector<char> litere_introduse;
    int vieti = 6;

    cout << "JOCUL \"SPANZURATOAREA\""<<endl<< "Ghiceste cuvantul secret!" << endl;

    while (vieti > 0) 
    {
        afisare_spanzuratoare(vieti);
        afisare_cuvant(cuvant_secret, litere_introduse);
        cout << "Incercari ramase: " << vieti << endl;
        cout << "Alege o litera: "<<endl;

        char incercare;
        cin >> incercare;
        incercare = tolower(incercare);

        if (find(litere_introduse.begin(), litere_introduse.end(), incercare) != litere_introduse.end()) 
        {
            cout << "Ai mai incercat aceasta litera '" << incercare << "'! Introdu alta.\n" << endl;
        }

        litere_introduse.push_back(incercare);

        if (cuvant_secret.find(incercare) != string::npos) 
        {
            cout << "Bravo! Litera '" << incercare << "' exista in cuvant.\n" << endl;
        }
        else 
        {
            cout << "Litera '" << incercare << "' nu este in cuvant.\n" << endl;
            vieti--;
        }

        if (cuvant_ghicit(cuvant_secret, litere_introduse)) 
        {
            cout << "\nFelicitari! Ai ghicit cuvantul: " << cuvant_secret << endl;
            break;
        }
    }

    if (vieti == 0) 
    {
        afisare_spanzuratoare(vieti);
        cout << "Game Over! Cuvantul era: " << cuvant_secret << endl;
    }

    return 0;
}
