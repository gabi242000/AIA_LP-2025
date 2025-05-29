#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <windows.h>

using namespace std;

int intrebariQuiz(const string& numeFisier, int& scor, int& nr_intrebari) {

    ifstream fisier(numeFisier);
    if (!fisier) {
        cerr << "Eroare la deschiderea fisierului: " << numeFisier << "\n";
        return 1;
    }
    string raspuns;
    string intrebare, a, b, c, d;
    string raspuns_corect;

    while(getline(fisier,intrebare)){
     getline(fisier,a);
     getline(fisier,b);
     getline(fisier,c);
     getline(fisier,d);
     getline(fisier,raspuns_corect);

     cout<<intrebare<<endl;
     cout<<a<<endl;
     cout<<b<<endl;
     cout<<c<<endl;
     cout<<d<<endl;

     cout<<"Răspuns: ";
     cin>>raspuns;
     raspuns[0]=tolower(raspuns[0]);
     if(raspuns==raspuns_corect){
        cout<<"\033[32mCorect!\033[0m"<<endl;
        scor++;
        Sleep(2000);
      }
     else {
        cout<<"\033[31mGreșit!\033[0m Răspunsul corect este: "<<raspuns_corect<<endl;
        Sleep(2000);
        }
     nr_intrebari++;
     cout<<endl;
}
    fisier.close();
    return 0;
}

int main(){
    cout<<endl;
    cout<<"\033[35m*************** TRIVIA QUIZ ***************\033[0m"<<endl<<endl;
    string nume;
    cout<<"Introdu numele: ";
    cin>>nume;
    cout<<"Bună, "<<nume<<"! Care să fie gradul de dificultate al întrebărilor?"<<endl;
    cout<<"1. Mediu"<<endl;
    cout<<"2. Dificil"<<endl;
    int dificultate;
    cout<<"Introdu opțiunea (1 sau 2): ";
    cin>>dificultate;
    cout<<"Să începem, "<<nume<<"!"<<endl;
    Sleep(2000);
    cout<<endl;

    string raspuns, raspuns_corect;
    int scor=0,nr_intrebari=0;
    
    switch(dificultate){
        case 1: {
            intrebariQuiz("mediu.txt", scor, nr_intrebari);
            break;
        }
        case 2:{
            intrebariQuiz("dificil.txt", scor, nr_intrebari);
            break;
        }
        default:{
            cout << "Opțiune invalidă!" << endl;
            return 1;
        }
    }
   
    cout<<"Acestea au fost întrebările. Mulțumesc pentru răspunsuri!"<<endl;
    cout<<"Se calculează scorul.."<<endl;
    Sleep(4000);
    cout<<endl;
    cout<<"\033[35m   Rezultat \033[0m"<<endl<<endl;
    Sleep(2000);
    if (scor > nr_intrebari / 2) 
        cout << "Felicitări!";
    else 
        cout << "Mai mult noroc data viitoare!";
    cout<<endl;
    cout<<nume<<" ai răspuns corect la "<<scor<<" întrebări din "<<nr_intrebari<<"!"<<endl;

    return 0;
}