#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>  

using namespace std;

const int ROWS = 9;
const int COLS = 9;
const int MINES = 10;

struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

vector<vector<Cell>> board(ROWS, vector<Cell>(COLS));
bool gameOver = false;

bool inBounds(int r, int c) {
    return r >= 0 && r < ROWS && c >= 0 && c < COLS;
}

void placeMines(int safeRow, int safeCol) {
    int placed = 0;
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (!board[r][c].isMine && !(r == safeRow && c == safeCol)) {
            board[r][c].isMine = true;
            placed++;
        }
    }

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (!board[r][c].isMine) {
                int count = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if (inBounds(nr, nc) && board[nr][nc].isMine)
                            count++;
                    }
                }
                board[r][c].adjacentMines = count;
            }
        }
    }
}

void printBoard(bool revealAll = false) {
    cout << "    ";
    for (int c = 0; c < COLS; ++c)
        cout << c + 1 << ' ';
    cout << "\n";

    for (int r = 0; r < ROWS; ++r) {
        cout << r + 1 << " | ";
        for (int c = 0; c < COLS; ++c) {
            Cell &cell = board[r][c];
            if (revealAll || cell.isRevealed) {
                if (cell.isMine) cout << "* ";
                else cout << cell.adjacentMines << ' ';
            } else if (cell.isFlagged) {
                cout << "F ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void reveal(int r, int c) {
    if (!inBounds(r, c) || board[r][c].isRevealed || board[r][c].isFlagged)
        return;

    board[r][c].isRevealed = true;

    if (board[r][c].isMine) {
        gameOver = true;
        return;
    }

    if (board[r][c].adjacentMines == 0) {
        for (int dr = -1; dr <= 1; ++dr)
            for (int dc = -1; dc <= 1; ++dc)
                if (dr != 0 || dc != 0)
                    reveal(r + dr, c + dc);
    }
}

bool checkWin() {
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            if (!board[r][c].isMine && !board[r][c].isRevealed)
                return false;
    return true;
}

int main() {
    srand(time(0));

    char playAgain;
    do {

        board = vector<vector<Cell>>(ROWS, vector<Cell>(COLS));
        gameOver = false;
        bool firstMove = true;

        while (!gameOver) {
            printBoard();
            cout << "\n(r <linie> <coloana> pentru reveal, f <linie> <coloana> pentru flag): ";

            string input;
            getline(cin, input); 

            char cmd;
            int r, c;
            stringstream ss(input);
            if (!(ss >> cmd >> r >> c)) {
                cout << "Nu nu!Nu asa!.\n";
                continue;
            }

            r--; c--;

            if (!inBounds(r, c)) {
                cout << "Cam departe te duci Domnule! (1 - " << ROWS << ")\n";
                continue;
            }

            if (cmd == 'f') {
                if (!board[r][c].isRevealed)
                    board[r][c].isFlagged = !board[r][c].isFlagged;
                else
                    cout << "Ho ca nu-i nimic acolo!.\n";
            } else if (cmd == 'r') {
                if (firstMove) {
                    placeMines(r, c);
                    firstMove = false;
                }

                reveal(r, c);

                if (gameOver) {
                    printBoard(true);
                    cout << "\n Ai Explodat!Womp Womp!.\n";
                    break;
                }

                if (checkWin()) {
                    printBoard(true);
                    cout << "\n Bravo!Ai facut si tu ceva!\n";
                    break;
                }
            } else {
                cout << "Nu cunosc :(.\n";
            }
        }

        cout << "\nVrei sa mai incerci?? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}