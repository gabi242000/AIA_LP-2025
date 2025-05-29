#include "Story.h"
#include "Casino.h"
#include "User.h"
#include "Jobs.h"
#include "Study.h"
#include "Shop.h"

#include <iostream>



using namespace std;
extern  Casino casino;
extern User user;
extern Jobs jobs;
extern Study study;
extern Shop shop;

/*vector<int> Make_Activities(unordered_map<string,int> pos) {
    vector<int> res;
    for (auto i : pos) {
        res.push_back(i.second);
    }
    return res;

}*/
void Story::ActivityUpdate() {

    switch (user.age) {
        case 4:
            Posible_Activites[0].first = 0;
            Posible_Activites[1].first = 1; //unlocks studying
            break;
        case 18:
            Posible_Activites[2].first = 1;
            Posible_Activites[3].first = 1;
            Posible_Activites[4].first = 1;
            Posible_Activites[5].first = 1;
            break;
        case 19:
            if (!Story::everBeenToUni) {
                Posible_Activites[7].first = 1;
            }
            break;
        default:
            break;
    }
}

void Story::Activity() {
    ActivityUpdate();
    if (!user.alive)return;
    string choice;
    cout<<"\nWhat would you like to do?\n";
    for (int i=0;i<Posible_Activites.size();i++) {
        if (Posible_Activites[i].first == 1) {
            cout<<i<<". "<<Posible_Activites[i].second<<endl;
        }
    }

    while (true) {
        cin>>choice;
        if (Posible_Activites[stoi(choice)].first != 1 || stoi(choice) > Posible_Activites.size()) {
            cout<<"Please enter a valid option!";
        }
        else
            break;

    }

    switch(stoi(choice)) {
        case 0:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            cout<<"You skiped a year!\n";
            user.age++;
            break;
        case 1:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            study.StudyHard();
            break;
        case 2:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            if (user.ocupation!="") {
                jobs.Work();
            }
            else {
                string answer;
                cout<<"You dont have a job!\n";
                cout<<"Would you like to work as a barista? Type yes or no\n";
                while (true) {
                    cin>>answer;
                    if (answer == "yes") {
                        user.ocupation = "Barista";
                        user.sanityLoss = 3;
                        break;
                    }
                    else if (answer == "no") {
                        break;
                    }
                    else
                        cout<<"Please enter a valid option\n";
                }
            }

            break;
        case 3:
            shop.Store();
            break;
        case 4:
            //inventory
            break;
        case 5:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            casino.ShowGames();
            break;
        case 6:
            user.ShowPlayerStats();
            break;
        case 7:
            if (user.checkIfYouWannaKys()) {Story::Activity();return;}
            study.ChooseUniversity();
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 1000: {

        }
        default:cout<<"Wrong input!!!\n";break;
    }
}



/*
 0: skip year
 1: study
 2: work
 3: shop
 4: invetory
 5: casino
 6: partner
 7: check stats

 */
/*
void Activites() {
    cout<<"What would you like to do?\n";

    if (1 == 2) {
        cout<<"piticule baga banii in masini nu in masinarii\n";

    }
    else {

        cout<<"0. wait\n"
            <<"1. Gamble\n"
            <<"2. Work\n"
            <<"3. Get a job"
            <<"4. Study\n"
            <<"5. Just die u fucking twat\n"
            <<"6. Check stats\n";

        int choice;
        cin>>choice;
        switch (choice) {
            case 0: {

            }
            case 1: {
                casino.ShowGames();
                break;
            }
            case 2: {

            }
            case 3: {
                jobs.GetAJob();
            }
            case 4:


            case 5: {
                user.alive = false;
                break;
            }
            case 6: {
                user.ShowPlayerStats();
            }
        }
    }

}*/

//adictii (16 ani alege 1)
    //fumat -2strs,-1000 bani//70-hp(primesti aura de fumator)
    //alcool<3 -3int/an -1000$$//70-hp (primesti puncte x1.1)
    //droage -3stress -5int - 4000 //50// rehab (scapi de adicite) -10000$
    //zahar -1stres -5000$//75hp
//18
/*  GAMBLE
 *  FACULTA (int/an)
 *  JOB (ceva mic)
 *  Partener -Bani, +Mij
 */
//+30
/*
 * Copii -bani ++stress +Pct
 * Nevasta -bani ++stress +Pct
 * Divort +bani --stress -Bani copii
 */
//FINAL
/*
    Mori....
        Primesti puncte
        -Numele +10char +=69pct
        per an trait +=100
        1pct/1000$
        per copil +=5000
        Partener +=2000
        Gamble +1 per win si -1 per lose
        Per int +=10
        job/faculta/per an+= niste puncte


*/