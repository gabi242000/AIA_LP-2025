#ifndef USER_H
#define USER_H

////////Libraries////////////
#include<string>
#include<vector>

using namespace std;



class User {
public:
        int age,money,moneyPerYear,stress, lifeExpentence, health,inteligence, kids, sanity, sanityLoss;
        string name,ocupation,study,uniSpec;
        vector<string> degree;
        vector<string> unlockedActivities;
        bool alive, married;

        //////methods///////
        void ShowPlayerStats();
        void KillYourself(bool alive);
        int calculateLifeExpentence();

        bool checkIfYouWannaKys();
};



#endif //USER_H
