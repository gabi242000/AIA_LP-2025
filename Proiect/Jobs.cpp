#include "Jobs.h"
#include "User.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

extern User user;

void Jobs::Work() {
    string job = user.ocupation;
    cout<<"You are working as a: "<<job<<"\n";
    if(Jobs::salaries.count(job) != 0) {
        while (true) {
           user.age = user.age + 1;
            user.money += Jobs::salaries[job];
            user.sanity -= user.sanityLoss;
            cout<<"You earned "<< Jobs::salaries[job]<< " RON this year! \n"
                <<"You now have "<<user.money<<" RON'\n"
                <<"Your sanity level is "<<user.sanity<<endl
                <<"Do you wish to work for another year? Type yes or no \n";
            string answer;
            while (true) {
                cin>>answer;
                if (answer == "yes")
                    break;
                else if (answer == "no") {
                    return;
                }
                else
                    cout<<"Please enter a valid option\n";
            }

            //user.lifeExpentence = user.calculateLifeExpentence();
            if (user.age >= 60)//user.lifeExpentence
                return;
        }
    }
    else
        cout<<"Esti somer varule";
}

void Jobs::GetAJob() {
    cout<<"You are looking for a job\n"
        <<"You can get these jobs for now:\n";
        int ind=user.degree.size();
        for (auto posibleJobs : user.degree) {
        cout<<ind<<". "<<posibleJobs<<endl;
        }
    cout<<"6. Barista";
    cout<<"Type the job number to get it:\n";
    cout<<"0 to Exit";
    int choice;
    cin>>choice;
    switch (choice) {
        case 0: return;break;

        case 1: user.ocupation = uniSpecToJob[user.uniSpec];cout<<"Congrats you are now a "<<user.ocupation<<"!!";break;

        case 6: user.ocupation="Barista";cout<<"Congrats you are now a Barista!!";break;
        default:"Please write a job number or leave!!\n";Jobs::GetAJob();break;
    }

    user.moneyPerYear=salaries[user.ocupation];
    cout<<"And you earn "
        <<salaries[user.ocupation]<<" per year";
}

