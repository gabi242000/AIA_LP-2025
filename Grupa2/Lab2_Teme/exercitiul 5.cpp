#include  <iostream>
using namespace std;

int main (){
    int nota;
    cout << "Introduce-ti nota dorita: " <<endl;
    cout << "10-Excelent" << endl;
    cout << "9-Foarte bine" << endl;
    cout << "8-Bine" << endl;
    cout << "7-Satisfacator" << endl;
    cout << "6-Suficient" << endl;
    cout << "5-Insuficient" << endl;
    cout << "4-Sub medie" << endl;
    cout << "3-Slab" << endl;
    cout << "2-Foarte slab" << endl;
    cout << "1-Dezastruos" << endl;
    cin >> nota;

    switch(nota){

    case 10:
    cout <<"Excelent";
    break;

    case 9:
    cout <<  "Foarte bine";
    break;

    case 8: 
    cout << "Bine";
    break;

    case 7:
    cout << "Satisfacator";
    break;
    
    case 6:
    cout << "Suficient";    
    break;

    case 5:
    cout << "Insuficient";
    break;

    case 4:
    cout << "Sub medie";
    break;

    case 3:
    cout << "Slab";
    break;

    case 2:
    cout << "Foarte slab";
    break;

    case 1: 
    cout << "Dezastruos";
    break;

    default:
    cout << "Nota introdusa nu exista in sistem";
    break;\

    return 0;
}
}