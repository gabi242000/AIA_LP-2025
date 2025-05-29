//
// Created by costijk on 5/28/25.
//

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


void Shop::Store() {
    cout<<"Available balance: "<<user.money<<" RON\n";
    cout<<"What would you like to buy?\n"
        <<"0. Go back\n"
        <<"1. Sanity pill (it restores your sanity by 25%, you can't go over 100%) - 840000 RON\n";

    string choice;
    while (true) {
        cin>>choice;
        if (stoi(choice) >= 0 && stoi(choice) <=1) {
            break;
        }
        else
            cout<<"Please enter a valid option\n";
    }

    switch (stoi(choice)) {
        case 0:
            break;
        case 1:
            if (user.money < 840000) {
                cout<<"You don't have enough money! \n";
                break;
            }

            user.sanity += 25;
            if (user.sanity > 100)
                user.sanity = 100;
            break;

        default:
            break;

    }
}