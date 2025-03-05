#include <iostream>
using namespace std;
int main()
{
    int nota;
    cout << "Va rog introduceti o nota de la 1 la 10: ";
    cin >> nota;
    switch(nota)
    {
        case 1:
            cout << "Cam proasta nota puiule" << endl;
            break;
        case 2:
            cout << "Dormi pe pres" << endl;
            break;
        case 3:
            cout << "Lasa lolu" << endl;
            break;
        case 4:
            cout << "Cam naspa mosule" << endl;
            break;
        case 5:
            cout << "Macar e de trecere" << endl;
            break;
        case 6:
            cout << "De acum pune mana si invata" << endl;
            break;
        case 7:
            cout << "Nu prea ai invatat" << endl;
            break;
        case 8:
            cout << "Binisor" << endl;
            break;
        case 9:
            cout << "Foarte bine" << endl;
            break;
        case 10:
            cout << "Cam tocilar" << endl;
            break;
        default:
            cout << "Te rog introdu o nota de la 1 la 10" << endl;
    }
    return 0;
}
