
#include "Deck_Of_Cards.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

void Deck_Of_Cards::Shuffle() {
    srand(time(NULL));
    int rng = rand()%10000;
    for (const string& suit : suits) {
        for (int rank = 1; rank <= 13; ++rank) {
            deck.push_back(pair<string, int>(suit, rank));
        }
    }
    //random_shuffle(deck.begin(),deck.end());

    shuffle(deck.begin(), deck.end(), default_random_engine(rng));
}