#ifndef STORY_H
#define STORY_H
#include <string>
#include<unordered_map>
#include <vector>

using namespace std;

class Story {
    public:
        vector<pair<int,string>> Posible_Activites={{1,"Wait a year"},{0,"Study"},{0,"Work"},{0,"shop"},{0,"Inventory"},{0,"Casino"},{1,"Check stats"}, {0,"ChooseUniversity"}};
        //vector<int> Posible_Activities;
        bool everBeenToUni = false;
        void Activity();
        void ActivityUpdate();
};



#endif
