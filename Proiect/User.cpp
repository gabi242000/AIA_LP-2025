#include "User.h"

#include <iostream>
#include <random>

using namespace std;


void User::ShowPlayerStats() {
    cout<<name<<endl;
    cout<<"Your age is: "<<age<<endl;
    cout<<"Your balance: "<<money<<"RON"<<endl;
    cout<<"You make per month: "<<moneyPerYear<<"RON"<<endl;
    cout<<"Your sanity is at: "<<sanity<<"%"<<endl;
    cout<<"Your ocupation is: "<<ocupation<<endl;
    cout<<"You study at: "<<study<<endl;
    cout<<"Your inteligence is: "<<inteligence<<endl;
}
string textFix() {
    string answear;
    while (true) {
        cin>>answear;
        if (answear == "yes" || answear == "no")
            return answear;
        else
            cout<<"Please enter a valid option\n";
    }
}

bool User::checkIfYouWannaKys() {
    string question = "Do you want to unalive yourself? Type yes or no\n", answer;
    srand(time(0));
    int chance;
    chance = rand()%100;
    bool itShowed = false;


    if (sanity > 50) {
        itShowed = false;
    }
    else if (sanity > 40) {
        if (chance < 10) {
            cout<<question<<endl;
            answer = textFix();
            itShowed = true;
        }
    }
    else if (sanity > 30) {
        if (chance < 20) {
            cout<<question<<endl;
            answer = textFix();
            itShowed = true;
        }
    }
    else if (sanity > 20) {
        if (chance < 30) {
            cout<<question<<endl;
            answer = textFix();
            itShowed = true;
        }
    }
    else if (sanity > 10) {
        if (chance < 40) {
            cout<<question<<endl;
            answer = textFix();
             itShowed = true;
        }
    }
    else if (sanity > 0) {
        if (chance < 50) {
            cout<<question<<endl;
            answer = textFix();
            itShowed = true;
        }
    }
    else{
        cout<<question<<endl;
        answer = textFix();
        itShowed = true;
    }

    if (answer == "yes") {
        alive = false;
        return true;
    }
    else if (answer == "no") {
        cout<<"You are still alive!\n";

    }

    return itShowed;

}



// 100 , 20 , 10