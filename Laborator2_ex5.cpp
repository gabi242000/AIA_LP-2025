# include <iostream>

using namespace std;

int main()
{   int nota;
    cout<<"Introduceti nota: ";
    cin>>nota;
    cout<<"Nota ta este: "<<nota<<endl;
    switch(nota)
    {
        case 10: cout<<"Excelent";
        break;
        case 9: cout<<"Foarte bine";
        break;
        case 8: cout<<"Destul de bine";
        break;
        case 7: cout<<"Bine";
        break;
        case 6: cout<<"Binisor";
        break;
        case 5: cout<<"Satisfacator";
        break;
        case 4: cout<<"Insuficient";
        break;
        case 3: cout<<"Rau";
        break;
        case 2: cout<<"Foarte rau";
        break;
        case 1: cout<<"Dezamagitor";
        break;
        default: cout<<"Nota invalida"; 
        break;

    }
    return 0;
}