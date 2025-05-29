#ifndef CASINO_H
#define CASINO_H

//robicu isi pierde ciocanu la aparate xddddd

class Casino{
public:
    int balance=0;
    ///////methods
    void ShowGames();
    void Deposit();
    void Withdraw();

    //Casino games
    void Blackjack();
    void Dices();
    void SlotsStart();
    void Roulet();
    void Baccarat();

    void bbnoSS(int balance);
    void playAGame(int game);
};




#endif //CASINO_H
