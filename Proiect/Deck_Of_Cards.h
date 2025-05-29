
#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Deck_Of_Cards {
        public:
        vector<string> suits = {"diamond", "club", "heart", "spade"};
        vector<pair<string, int>> deck;



        void Shuffle();
};



#endif //DECK_OF_CARDS_H
