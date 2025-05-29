#include "Study.h"
#include "User.h"
#include "QualityTools.h"
#include "Story.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>


extern User user;
extern QualityTools qualityTools;
extern Story story;

void Study::StudyHard() {

    if (user.study == "Medical") {
        user.inteligence += intGain;
        user.sanity -= 3;
        uni++;
        if (uni >= 4) {
            cout<<"You passed the university\n";
            cout<<"You know work as a medic";
            user.ocupation = "Doctor";
            user.study = "Homeschool";
            user.sanityLoss = 8;
        }
    }
    else if (user.age <=3) {
        cout<<"You are too young to study try when you are a bit older (4 years old)!!\n";
        return;
    }
    else if (user.study == ""&&kind ==0&&user.age>=studyAt["kindergarden"]) {
            cout<<"Welcome to the kindergarden!\n";
            user.study="Kindergarden";
            kind++;
    }
    else {
            if (user.age >= studyAt["School"] && kind >= 3 && school == 0) {
                cout << "Welcome to the school!\n";
                user.study="School";
                Study::intGain = 2;
            }
            if (user.age>=studyAt["Highschool"]&& school >=8 && high == 0) {
                user.study="Highschool";
                cout << "Welcome to the highschool!\n";
                Study::intGain = 3;
            }
            if (user.age>=studyAt["Homeschool"]&& high > 4 && Study::intGain != 3) {
                user.study="Homeschool";
                cout << "Congrats you graduted highschool! Now you are able to learn by yourself\n";
                Study::intGain = 4;
            }


            if (user.study=="Kindergarden") {
                kind++;

            }
            if (user.study=="School") {
                school++;

            }
            if (user.study=="Highschool") {
                high++;
            }

            user.inteligence += intGain;

            if (user.study=="Homeschool") {
                user.sanity -= 2;
            }
    }
    user.age +=1;


   /* if (user.study=="University"&&uni<=3) {
        user.inteligence+= uniSpec[user.study];
        user.stress +=sterssLevelPerSession[user.uniSpec];
        uni++;
    }else {
        user.inteligence+= studyAt[user.study];
        user.degree.push_back(user.uniSpec);
        user.uniSpec="";
    } */

}
void Study::ChooseUniversity() {
    string option;
    bool passed;

    cout<<"Choose one option(the exam will be harder based on your inteligence): \n";
    cout<<"inteligence: "<<user.inteligence<<"\n";
    cout<<"0. Go back\n"
        <<"1. Medical  inteligence: 40\n";

    while (true) {
        cin>>option;
        if (stoi(option) == 1 || stoi(option) == 0)
            break;
        else
            cout<<"Invalid option\n";
    }

    switch (stoi(option)) {
        case 0:
            break;
        case 1:
            passed = interviewMedical();
            if (passed) {
                cout<<"Congrats you passed the examn! Now you can start studying at the Medical School\n";
                user.study="Medical";
                intGain = 5;
                story.everBeenToUni = true;
                story.Posible_Activites[7].first = 0;

            }
            else {
                cout<<"You failed! Good luck next time!";
                user.sanity -= 5;
            }
    }
}

bool Study::interviewMedical() {

    ifstream medicalRead("intrebari/medical.txt");
    vector<pair<string,vector<string>>> interviewMedicalQuestions;
    for (int i = 0; i < 64; i++) {
        string question;
        vector<string> responses;
        getline(medicalRead, question);
        for (int j = 0; j < 4; j++) {
            string response;
            getline(medicalRead, response);
            responses.push_back(response);
        }
        interviewMedicalQuestions.push_back(make_pair(question, responses));
    }

    auto rng = default_random_engine{};
    ranges::shuffle(interviewMedicalQuestions, rng);

    // for (int i = 0; i < interviewMedicalQuestions.size(); i++) {
    //     cout<<interviewMedicalQuestions[i].first;
    //     cout<<interviewMedicalQuestions[i].second[0];
    //     cout<<interviewMedicalQuestions[i].second[1];
    //     cout<<interviewMedicalQuestions[i].second[2];
    //     cout<<interviewMedicalQuestions[i].second[3]<<endl;
    //     cout<<i<<endl;
    // }


    medicalRead.close();



    int correctResponses = 0, cursingLevel = 0;

    if (user.inteligence < Study::inteligent_req["Medical"]) {
        cursingLevel = Study::inteligent_req["Medical"]-user.inteligence;
    }
    int goodResponses = 0, minimum = 21;
    for (int i = 0; i < 30; i++) {
        string question;
        question.append(interviewMedicalQuestions[i].first, 0, interviewMedicalQuestions[i].first.size()-2);
        char correct = interviewMedicalQuestions[i].first[interviewMedicalQuestions[i].first.size() - 1];
        question = qualityTools.curse(question, cursingLevel);
        cout<<i+1<<": "<<question<<endl;
        cout<<interviewMedicalQuestions[i].second[0]<<endl;
        cout<<interviewMedicalQuestions[i].second[1]<<endl;
        cout<<interviewMedicalQuestions[i].second[2]<<endl;
        cout<<interviewMedicalQuestions[i].second[3]<<endl;
       cout<<"Psst raspunsul corect este "<< correct<<endl;
        char response;
        cin>>response;

        if (response == correct) {
            cout<<"Good\n";
            goodResponses++;
        }
        else
            cout<<"Bad\n";
    }


    cout<<"You got " << goodResponses <<" out of 30\n";
    if (goodResponses >= minimum)
        return true;



    return false;
}