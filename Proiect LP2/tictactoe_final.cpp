#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player = 'X';
bool gameOver = false;
int score_X = 0, score_0 = 0;

void resetBoard() 
{
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void creating_board() 
{
    cout << "Tic Tac Toe Game\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

bool isNumber(string s) 
{
    if (s.length() != 1) return false;
    return s[0] >= '1' && s[0] <= '9';
}

bool checkWin()
{
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;
    return false;
}

bool isDraw() 
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != '0')
                return false;
    return true;
}

void position()
{
    string poz;
    bool validMove = false;
    
    while (!validMove) 
    {
        cout << "Este randul jucatorului " << player << ". Introdu pozitia (intre 1 si 9): ";
        cin >> poz;

        if (!isNumber(poz)) 
        {
            cout << "EROARE: Trebuie sa introduci un singur caracter valid intre 1 si 9!" << endl;
            continue;
        }

        int l = poz[0] - '0';
        int coloana,rand;
        switch(l)
    {
        case 1: rand=0; coloana=0; break;
        case 2: rand=0; coloana=1; break;
        case 3: rand=0; coloana=2; break;
        case 4: rand=1; coloana=0; break;
        case 5: rand=1; coloana=1; break;
        case 6: rand=1; coloana=2; break;
        case 7: rand=2; coloana=0; break;
        case 8: rand=2; coloana=1; break;
        case 9: rand=2; coloana=2; break;
    }

        if (board[rand][coloana] == 'X' || board[rand][coloana] == '0') 
        {
            cout << "Pozitia selectata este deja ocupata! Introdu alta.\n";
            continue;
        }

        board[rand][coloana] = player;
        validMove = true;
    }

    creating_board();

    if (checkWin())
    {
        cout << "Jucatorul " << player << " a castigat runda!" << endl;
        if (player == 'X') score_X++;
        else score_0++;
        gameOver = true;
    }
    else if (isDraw()) 
    {
        cout << "Egalitate! Runda s-a terminat." << endl;
        gameOver = true;
    }
    if (player == 'X') 
    {
    player = '0';
    } 
    else 
    {
    player = 'X';
    }
}

int main() 
{
    char playAgain;
    do {
        resetBoard();
        player = 'X';
        gameOver = false;
        creating_board();
        while (!gameOver) 
        {
            position();
        }

        cout << "Scor final: Jucator X = " << score_X << " | Jucator 0 = " << score_0 << endl;
        cout << "Vrei sa joci din nou? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'n' || playAgain == 'N') 
        {
            cout << "Vrei sa resetezi scorul? (y/n): ";
            char resetScore;
            cin >> resetScore;
            if (resetScore == 'y' || resetScore == 'Y') 
            {
                score_X = 0;
                score_0 = 0;
            }
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Jocul s-a terminat! Multumesc ca ai jucat si sper ca te-ai distrat!" << endl;
    return 0; 
}