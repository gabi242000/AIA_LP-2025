#include <iostream>
#include <string>
#include <fstream>
#include <limits>  // ofera informatii despre limitele max si min ale inputurilor 
using namespace std;

#define MAX_CARTI 100000 //limita maxima de carti permise in biblioteca

int optiune1, filtru, nr_carti;
string titlu_find, titlu_edit, yes = "da", da_find = "da", da_edit = "da", da_delete = "da", optiune_meniu = "da" ;
bool go = true;

struct date{
    int day;
    int month;
    int year;
};

struct book{
    string title;
    string author;
    string category;
    string format;  
    string status;                
    int rating;                     
    int nr_pages;
    string bought_from;             
    date start_date;
    date finish_date;
    date buy_date;
};

book biblioteca[MAX_CARTI];

string tolower_string(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int valid_date(date d) {
  if(d.day< 1)
    return 0;
  if(d.month < 1 || d.month > 12)
    return 0;
  if(d.year < 999 || d.year > 10000)
    return 0;
  if(d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12) {
    if(d.day > 31)
       return 0;
  }
  else if(d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
         if(d.day > 30)
            return 0;
  }
  else if(d.month == 2 && d.year % 4 == 0) {
         if(d.day > 29)
            return 0;
  }
  else if(d.month == 2 && d.year % 4 != 0) {
         if(d.day > 28)
            return 0;
  }
  return 1;

}

int get_valid_int(const string& message) {
  int val;
  while(true) {
    cout << message;
    if(cin >> val) {
      cin.ignore();
      return val;
    }
    else {
      cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
      cin.clear(); //reseteaza starea lui cin, care se afla modul de eroare
      cin.ignore(numeric_limits<streamsize>::max(), '\n');   // ignora caracterele introduse gresit pana la '\n'
      //numeric_limits<streamsize>::max() este functie specifica <limits> care returneaza
      //valoarea maxima posibila pentru streamsize (tip intreg folosit de stream-uri (cin, cout))
    }

  }
}

void save_books() {
    ofstream fout("C:\\Users\\lavin\\Documents\\UTCB 2024 - 2025\\library_management_system\\books.txt");
    if(!fout.is_open()) {
        cerr << "❌ Eroare la deschiderea fisierului!\n";
        return;
    }

    for(int i = 0; i < nr_carti; i++) {
        fout << biblioteca[i].title << ";"
             << biblioteca[i].author << ";"
             << biblioteca[i].category << ";"
             << biblioteca[i].format << ";"
             << biblioteca[i].status << ";"
             << biblioteca[i].rating << ";"
             << biblioteca[i].nr_pages << ";"
             << biblioteca[i].bought_from << ";"
             << biblioteca[i].buy_date.day << " " << biblioteca[i].buy_date.month << " " << biblioteca[i].buy_date.year << ";"
             << biblioteca[i].start_date.day << " " << biblioteca[i].start_date.month << " " << biblioteca[i].start_date.year << ";"
             << biblioteca[i].finish_date.day << " " << biblioteca[i].finish_date.month << " " << biblioteca[i].finish_date.year << "\n";

    }
    fout.close();
}

void load_books() {
    nr_carti = 0;
    ifstream fin("C:\\Users\\lavin\\Documents\\UTCB 2024 - 2025\\library_management_system\\books.txt");
    if(!fin.is_open()) {
        cerr << "❌ Eroare la deschiderea fisierului!\n";
        return;
    }
    book b;
    while(getline(fin, b.title, ';')) {
        getline(fin, b.author, ';');
        getline(fin, b.category, ';');
        getline(fin, b.format, ';');
        getline(fin, b.status, ';');

        string ratingg;
        getline(fin, ratingg, ';');
        b.rating = stoi(ratingg);

        string nrpag;
        getline(fin, nrpag, ';');
        b.nr_pages = stoi(nrpag);

        getline(fin, b.bought_from, ';');

        fin >> b.buy_date.day >> b.buy_date.month >> b.buy_date.year;
        fin.ignore(1);  //ignore ';'
        fin >> b.start_date.day >> b.start_date.month >> b.start_date.year;
        fin.ignore(1);
        fin >> b.finish_date.day >> b.finish_date.month >> b.finish_date.year;
        fin.ignore();  //ignore '\n'

        biblioteca[nr_carti++] = b;

    }

    fin.close();
}

void add_book() {
    if(nr_carti >= MAX_CARTI) {
        cout << "😓Ups! Biblioteca este plina!\n";
        return;
    }

    book carte_noua;
    carte_noua.title = "";
    carte_noua.author = "";
    carte_noua.category = "";
    carte_noua.format = "";
    carte_noua.status = "";
    carte_noua.bought_from = "";
    carte_noua.rating = -1;
    carte_noua.nr_pages = 0;
    carte_noua.buy_date = {0, 0, 0};
    carte_noua.start_date = {0, 0, 0};
    carte_noua.finish_date = {0, 0, 0};
    cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
    cout << "                Introdu:\n\n";

    cout << "🔸Titlu: ";
    cin.ignore();
    getline(cin, carte_noua.title);

    cout << "🔸Autor: ";
    getline(cin, carte_noua.author);

    cout  << "🔸Categorie: ";
    getline(cin, carte_noua.category);

    cout << "🔸Format (fizic / ebook / audiobook): ";
    getline(cin, carte_noua.format);

    string buy_place;
    if(tolower_string(carte_noua.format) == "fizic") {
        cout << "\nDoresti sa introduci locul de unde ai cumparat cartea? (Da / Nu)\n"
             << "⇢ ";
        getline(cin, buy_place);
        if(tolower_string(buy_place) == "da") {
            cout << "🔸Loc achizitie: ";
            getline(cin, carte_noua.bought_from);
        }

        string buy_date;
        cout << "\nDoresti sa introduci data cand ai cumparat cartea? (Da / Nu)\n"
             << "⇢ ";
        getline(cin, buy_date);
        if(tolower_string(buy_date) == "da") {
          date date_buy;
          do{
            cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Data achizitiei ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
            date_buy.day = get_valid_int("🔸Zi (dd): ");
            date_buy.month = get_valid_int("🔸Luna (mm): ");
            date_buy.year = get_valid_int("🔸An (yyyy): ");

            if(!valid_date(date_buy)) 
              cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
            

          } while(!valid_date(date_buy));

          carte_noua.buy_date = date_buy;
        }
    }

    carte_noua.nr_pages = get_valid_int("🔸Numar de pagini: ");
    while(carte_noua.nr_pages <= 0) {
      cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
      carte_noua.nr_pages = get_valid_int("🔸Numar de pagini: ");
    }

    cout << "🔸Status (wishlist / citita): ";
    cin >> carte_noua.status;

    if(tolower_string(carte_noua.status) == "citita") {
       carte_noua.rating = get_valid_int("🔸Rating (0-10): ");
        while (carte_noua.rating < 0 || carte_noua.rating > 10) {
            cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
            carte_noua.rating = get_valid_int("🔸Rating (0-10): ");
        }
       
        string data;
        cout << "\nDoresti sa introduci perioada in care ai citit-o? (Da / Nu)\n"
             << "⇢ ";
        getline(cin, data);
        if(tolower_string(data) == "da") {
          date date_start, date_finish;

          do {
            cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ 🔸Data inceperii citirii ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
            date_start.day = get_valid_int("🔸Zi (dd): ");
            date_start.month = get_valid_int("🔸Luna (mm): ");
            date_start.year = get_valid_int("🔸An (yyyy): ");

            if(!valid_date(date_start)) 
               cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
            
          }while(!valid_date(date_start));

          carte_noua.start_date = date_start;
          
          do {
            cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ 🔸Data finalizarii citirii ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
            date_finish.day = get_valid_int("🔸Zi (dd): ");
            date_finish.month = get_valid_int("🔸Luna (mm): ");
            date_finish.year = get_valid_int("🔸An (yyyy): ");

            if(!valid_date(date_finish))
              cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";

          }while(!valid_date(date_finish));

          carte_noua.finish_date = date_finish;   
        }
      }
    biblioteca[nr_carti++] = carte_noua;
}

void show_details_book(string title) {
    bool gasit = false;
    
    for(int i = 0; i < nr_carti; i++) {
        if(tolower_string(biblioteca[i].title) == tolower_string(title)) {
            cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Detalii carte ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
            gasit = true;
            cout << "🔸Titlu: " << biblioteca[i].title << "\n";
            cout << "🔸Autor: " << biblioteca[i].author << "\n";
            cout << "🔸Categorie: " << biblioteca[i].category << "\n";
            cout << "🔸Format: " << biblioteca[i].format << "\n";
            cout << "🔸Numar de pagini: " << biblioteca[i].nr_pages << "\n";
            cout << "🔸Status: " << biblioteca[i].status << "\n";
            if(tolower_string(biblioteca[i].status) == "citita") {
                cout << "🔸Rating: " << biblioteca[i].rating << " / 10" << "\n";
                if(biblioteca[i].bought_from != "")
                   cout << "🔸Loc achizitie: " << biblioteca[i].bought_from << "\n";
                if(biblioteca[i].buy_date.day != 0)
                   cout << "🔸Data achizitie: " << biblioteca[i].buy_date.day << "/" << biblioteca[i].buy_date.month << "/" << biblioteca[i].buy_date.year << "\n";
                if(biblioteca[i].start_date.day != 0) {
                    cout << "🔸Data inceperii citirii: " << biblioteca[i].start_date.day << "/" << biblioteca[i].start_date.month << "/" << biblioteca[i].start_date.year << "\n";
                    cout << "🔸Data finalizarii citirii: " << biblioteca[i].finish_date.day << "/" << biblioteca[i].finish_date.month << "/" << biblioteca[i].finish_date.year << "\n";
                }
            } 
            cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
            break; 
        }
    }

    if(!gasit)
    cout << "😓Ups! Nu am gasit cartea.\n";
}

void show_sorted_books(int filter) {
    int indici[MAX_CARTI];
    int aux;
    for(int i = 0; i < nr_carti; i++)
        indici[i] = i;

    switch(filter) {
        case 1:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate alfabetic dupa autor ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";

          for(int i = 0; i < nr_carti - 1; i++) {
            for(int j = i + 1; j < nr_carti; j++) {
                if(tolower_string(biblioteca[indici[i]].author) > tolower_string(biblioteca[indici[j]].author)) {
                    aux = indici[i];
                    indici[i] = indici[j];
                    indici[j] = aux;
                }
            }
          }

          for(int i = 0; i < nr_carti; i++) {
            cout << biblioteca[indici[i]].author << " ‖ " << "\"" << biblioteca[indici[i]].title << "\"\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;

        case 2:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate in ordine alfabetica dupa titlu ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";

          for(int i = 0; i < nr_carti - 1; i++) {
            for(int j = i + 1; j < nr_carti; j++) {
                if(tolower_string(biblioteca[indici[i]].title) > tolower_string(biblioteca[indici[j]].title)) {
                    aux = indici[i];
                    indici[i] = indici[j];
                    indici[j] = aux;
                }
            }
          }

          for(int i = 0; i < nr_carti; i++) {
            cout << "\"" << biblioteca[indici[i]].title << "\"" << " ‖ " << biblioteca[indici[i]].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;
        
        case 3:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate dupa format ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          cout << "  1.Format fizic:\n";
          for(int i = 0; i < nr_carti; i++) {
            if(biblioteca[i].format == "fizic") {
                cout << "\"" << biblioteca[i].title << "\"" << " ‖ " << biblioteca[i].author << "\n";
            }
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          cout <<"\n  2.Format ebook:\n";
          for(int i = 0; i < nr_carti; i++) {
            if(biblioteca[i].format == "ebook") {
                cout << "\"" << biblioteca[i].title << "\"" << " ‖ " << biblioteca[i].author << "\n";
            }
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          cout <<"\n  3.Format audiobook:\n";
          for(int i = 0; i < nr_carti; i++) {
            if(biblioteca[i].format == "audiobook") {
                cout << "\"" << biblioteca[i].title << "\"" << " ‖ " << biblioteca[i].author << "\n";
            }
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;

        case 4:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate in ordine crescatoare dupa numarul de pagini ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          for(int i = 0; i < nr_carti - 1; i++) {
            for(int j = i + 1; j < nr_carti; j++) {
                if(biblioteca[indici[i]].nr_pages > biblioteca[indici[j]].nr_pages) {
                    aux = indici[i];
                    indici[i] = indici[j];
                    indici[j] = aux;
                }
            }
          }

          for(int i = 0; i < nr_carti; i++) {
            cout << biblioteca[indici[i]].nr_pages << " pagini" << " ‖ " << "\"" << biblioteca[indici[i]].title << "\"" << " ‖ " << biblioteca[indici[i]].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔=\n";
          break;

        case 5:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate crescator dupa rating ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          for(int i = 0; i < nr_carti - 1; i++) {
            for(int j = i + 1; j < nr_carti; j++) {
                if(biblioteca[indici[i]].rating > biblioteca[indici[j]].rating) {
                    aux = indici[i];
                    indici[i] = indici[j];
                    indici[j] = aux;
                }
            }
          }

          for(int i = 0; i < nr_carti; i++) {
            if(biblioteca[indici[i]].rating != 0)
              cout << biblioteca[indici[i]].rating << " / 10" << " ‖ " << "\"" << biblioteca[indici[i]].title << "\"" << " ‖ " << biblioteca[indici[i]].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;

        case 6:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Carti sortate dupa anul in care au fost citite ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          for(int i = 0; i < nr_carti - 1; i++) {
            for(int j = i + 1; j < nr_carti; j++) {
                if(biblioteca[indici[i]].finish_date.year > biblioteca[indici[j]].finish_date.year) {
                    aux = indici[i];
                    indici[i] = indici[j];
                    indici[j] = aux;
                }
            }
          }

          for(int i = 0; i < nr_carti; i++) {
                if(biblioteca[indici[i]].finish_date.year != 0) 
                    cout << biblioteca[indici[i]].finish_date.year << " ‖ " << "\"" << biblioteca[indici[i]].title << "\"" << " ‖ " << biblioteca[indici[i]].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;

        case 7:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Wishlist ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";

          for(int i = 0; i < nr_carti; i++) {
                if(tolower_string(biblioteca[i].status) == "wishlist") 
                    cout << "\"" << biblioteca[i].title << "\"" << " ‖ " << biblioteca[i].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;

        case 8:
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Toate cartile ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";

          for(int i = 0; i < nr_carti; i++) {
            cout << "\"" << biblioteca[i].title << "\"" << " ‖ " << biblioteca[i].author << "\n";
          }
          cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
          break;
    } 
}

void edit_book(string title) {
    bool gasit = false;
    int optiune_edit;

    for(int i = 0; i < nr_carti; i++) {
        if(tolower_string(biblioteca[i].title) == tolower_string(title)) {
            gasit = true;
            
            cout << "\nCe doresti sa modifici?\n"
                   << "  1. Titlu\n"
                   << "  2. Autor\n" 
                   << "  3. Categorie\n"
                   << "  4. Format\n"
                   << "  5. Status\n"
                   << "  6. Numar pagini\n"
                   << "  7. Rating\n"
                   << "  8. Loc achizie\n"
                   << "  9. Data achizitie\n"
                   << "  10. Data inceput citire\n"
                   << "  11. Data finalizare citire\n";     

            optiune_edit = get_valid_int("⇢ ");
            while(optiune_edit < 1 || optiune_edit > 11) {
              cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                optiune_edit = get_valid_int("⇢ ");
            }
            
            switch(optiune_edit) {
                case 1:
                  cout << "🔸Titlu nou: ";
                  getline(cin, biblioteca[i].title);
                  break;

                case 2:
                  cout << "🔸Autor nou: ";
                  getline(cin, biblioteca[i].author);
                  break;
                
                case 3:
                  cout << "🔸Categorie noua: ";
                  getline(cin, biblioteca[i].category);
                  break;

                case 4:
                  cout << "🔸Format nou: ";
                  getline(cin, biblioteca[i].format);
                  break;

                case 5:
                  cout << "🔸Status nou (wishlist / citita): ";
                  getline(cin, biblioteca[i].status);
                  break;

                case 6:
                  biblioteca[i].nr_pages = get_valid_int("🔸Numar nou de pagini: ");
                  while(biblioteca[i].nr_pages <= 0) {
                      cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                      biblioteca[i].nr_pages = get_valid_int("🔸Numar nou de pagini: ");
                  }
                  break;

                case 7:
                  biblioteca[i].rating = get_valid_int("🔸Rating nou (0-10): ");
                    while (biblioteca[i].rating < 0 || biblioteca[i].rating > 10) {
                        cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                        biblioteca[i].rating = get_valid_int("🔸Rating nou (0-10): ");
                    }
                  break;

                case 8:
                  cout << "🔸Loc achizitie nou: ";
                  getline(cin, biblioteca[i].bought_from);
                  break;
                
                case 9:
                  cout << "🔸Data achizitie noua:\n";
                  biblioteca[i].buy_date.day = get_valid_int("🔸Zi (dd): ");
                  biblioteca[i].buy_date.month = get_valid_int("🔸Luna (mm): ");
                  biblioteca[i].buy_date.year = get_valid_int("🔸An (yyyy): ");
                  while (!valid_date(biblioteca[i].buy_date)) {
                        cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                        biblioteca[i].buy_date.day = get_valid_int("🔸Zi (dd): ");
                        biblioteca[i].buy_date.month = get_valid_int("🔸Luna (mm): ");
                        biblioteca[i].buy_date.year = get_valid_int("🔸An (yyyy): ");
                    }
                  break;

                case 10:
                  cout << "🔸Data inceperii citirii:\n";
                  biblioteca[i].start_date.day = get_valid_int("🔸Zi (dd): ");
                  biblioteca[i].start_date.month = get_valid_int("🔸Luna (mm): ");
                  biblioteca[i].start_date.year = get_valid_int("🔸An (yyyy): ");
                  while (!valid_date(biblioteca[i].start_date)) {
                        cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                        biblioteca[i].start_date.day = get_valid_int("🔸Zi (dd): ");
                        biblioteca[i].start_date.month = get_valid_int("🔸Luna (mm): ");
                        biblioteca[i].start_date.year = get_valid_int("🔸An (yyyy): ");
                    }
                  break;

                case 11:
                  cout << "🔸Data finalizarii citirii:\n";
                  biblioteca[i].finish_date.day = get_valid_int("🔸Zi (dd): ");
                  biblioteca[i].finish_date.month = get_valid_int("🔸Luna (mm): ");
                  biblioteca[i].finish_date.year = get_valid_int("🔸An (yyyy): ");
                  while (!valid_date(biblioteca[i].finish_date)) {
                        cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                        biblioteca[i].finish_date.day = get_valid_int("🔸Zi (dd): ");
                        biblioteca[i].finish_date.month = get_valid_int("🔸Luna (mm): ");
                        biblioteca[i].finish_date.year = get_valid_int("🔸An (yyyy): ");
                    }
                  break;
            }
            break;
        }
    }
    if(!gasit) {
        cout << "😓Ups! Nu am gasit cartea.\n";
        return;
    }
    save_books();


}

void delete_book() {
    int index;
    cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔ Cartile disponibile ⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
    for(int i = 0; i < nr_carti; i++)
      cout << "  " << i + 1 << ". " << "\"" << biblioteca[i].title << "\"\n";

    index = get_valid_int("\nAlege numarul cartii pe care doresti sa o stergi: ");
    while (index < 1 || index > nr_carti) {
        cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
        index = get_valid_int("⇢ ");
    }

    for (int i = index - 1; i < nr_carti - 1; i++)
        biblioteca[i] = biblioteca[i + 1];
    
    nr_carti--;
    
}

int main() {
    cout << "\n\n<<< Bine ai venit la The Book Nook!😊📕 >>>\n";
    cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";

    load_books();

    while(go) {
        
        cout << "\nIntrodu numarul optiunii dorite:\n"
             << "  1. Adauga o carte\n"
             << "  2. Sorteaza cartile\n"
             << "  3. Cauta o carte\n"
             << "  4. Editeaza detaliile unei carti\n"
             << "  5. Sterge o carte\n"
             << "  6. Iesire\n";
                 
        optiune1 = get_valid_int("⇢ ");
        while (optiune1 < 1 || optiune1 > 6) {
            cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
            optiune1 = get_valid_int("⇢ ");
        }

        switch(optiune1) {
            case 1: 
                while(tolower_string(yes) == "da") {
                    add_book();
                    cout << "\nCartea a fost adaugata cu succes!🎉\n";
                    cout << "⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔⏔\n";
                    cout << "\nDoresti sa mai adaugi o carte? (Da / Nu)\n"
                         << "⇢ ";
                    getline(cin, yes);
                }
                 save_books();
                 break;

            case 2:
                  cout << "\nAlege cum doresti sa sortezi cartile:\n"
                       << "  1. Autor\n"
                       << "  2. Alfabetic dupa titlu\n"
                       << "  3. Format\n"
                       << "  4. Numar de pagini\n"
                       << "  5. Rating\n"
                       << "  6. Anul in care au fost citite\n"
                       << "  7. Wishlist\n"
                       << "  8. Fara sortare\n";
                  filtru = get_valid_int("⇢ ");
                  while (filtru < 1 || filtru > 8) {
                    cout << "🤔 Hmm...cred ca ai gresit ceva. Incearca din nou!\n";
                    filtru = get_valid_int("⇢ ");
                }
    
                 show_sorted_books(filtru);
                 break;  

            case 3:
                while(tolower_string(da_find) == "da") {
                    cout << "\nIntrodu titlul cartii cautate:\n"
                         << "⇢ ";
                    getline(cin, titlu_find);
                    show_details_book(titlu_find);  
                    cout << "\nCauti alta carte? (Da / Nu)\n"
                         << "⇢ ";
                    getline(cin, da_find);
                }
                break;

            case 4:
                while(tolower_string(da_edit) == "da") {
                    cout << "\nIntrodu titlul cartii pe care vrei sa o editezi:\n";
                    getline(cin, titlu_edit);
                    edit_book(titlu_edit);
                    cout << "\nDoresti sa editezi alta carte? (Da / Nu)\n"
                         << "⇢ ";
                    getline(cin, da_edit);
                }
                break;

            case 5:
              while(tolower_string(da_delete) == "da"){
                delete_book();
                cout << "Cartea a fost stearsa cu succes!🎉\n";
                cout << "\nDoresti sa stergi alta carte? (Da / Nu)\n"
                     << "⇢ ";
                getline(cin, da_delete);
              }
              save_books();
              break;
              
            case 6:
               go = false;
               cout << "Bye bye! Ne vedem data viitoare!😊✨✨\n";
               break; 
        }

        if(go) {
            cout << "\nDoresti sa alegi altceva? (Da / Nu)\n"
                 << "⇢ ";
            getline(cin, optiune_meniu);
            if(tolower_string(optiune_meniu) != "da") {
               go = false;
               cout << "Bye bye! Ne vedem data viitoare!😊✨✨\n";
            }
        }
    }

    return 0;
}
