#include<bits/stdc++.h>
using namespace std;

class Tic_Tac_toe {
private:
    char board[3][3];
    bool isPlayerOne = true, gameOver = false;
    int  cellRow, cellCol;
public:
    Tic_Tac_toe () {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 'v';
            }
        }
    }
    bool playerOne () {
        return isPlayerOne;
    }
    void displayBoard () {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'v') {
                    cout << "       ";
                } else {
                    cout << "   " << board[i][j] << "   ";
                }
                if(j != 2) cout << "|";
            }
            if (i != 2) cout << "\n-------------------------\n";
            else cout << "\n";
        }
    }
    int getInput () {
        if (isPlayerOne) {
            cout << "Player 1: Select a Cell: [row column]";
        } else {
            cout << "Player 2: Select a Cell: [row column]";
        }
        cin >> cellRow >> cellCol;
        if (board[cellRow][cellCol] != 'v') {
            getInput();
        } 
    }
    void boardMark () {
        if (isPlayerOne) {
            board[cellRow][cellCol] = 'X';
            isPlayerOne = false;
        } else {
            board[cellRow][cellCol] = 'o';
            isPlayerOne = true;
        }
    }
    bool gameOverCheck () {
        if ((board[0][0] == board[0][1] and board[0][1] == board[0][2] and board[0][1] != 'v') or  
            (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[1][1] != 'v') or
            (board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[1][0] != 'v') or
            (board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][1] != 'v') or
            (board[0][1] == board[1][1] and board[1][1] == board[2][1] and board[1][1] != 'v') or
            (board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][1] != 'v') or
            (board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[1][2] != 'v') or
            (board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[1][1] != 'v')) gameOver = true;
            return gameOver;
    }
    bool drawCheck() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'v') return false;
            }
        }
        return true;
    }
};

int main() {
    Tic_Tac_toe t1;
    while (1) {
        t1.getInput();
        t1.boardMark();
        t1.displayBoard();
        if (t1.gameOverCheck()) {
            if (t1.playerOne()) {
                cout << "Player 2 Wins the Game.";
            } else {
                cout << "Player 1 Wins the Game.";
            }
            break;
        }
        if (t1.drawCheck()) {
            cout << "The Game Ends In A Draw";
            break;
        }
    }
    return 0;
}