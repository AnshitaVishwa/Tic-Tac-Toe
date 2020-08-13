#include<bits/stdc++.h>
using namespace std;

class Tic_Tac_toe {
private:
    char board[3][3];
    bool isPlayerOne = true;
    int  cellRow, cellCol;
public:
    Tic_Tac_toe () {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 'v';
            }
        }
    }
    void changingTurn () {
        isPlayerOne = !isPlayerOne;
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
        cout << "Player 1: Select a Cell: [row column]";
        cin >> cellRow >> cellCol;
        if (board[cellRow][cellCol] != 'v') {
            getInput();
        } 
    }
    void boardMark () {
        board[cellRow][cellCol] = 'X';
    }
    bool drawCheck() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'v') return false;
            }
        }
        return true;
    }
    // evaluation function for who wins the game
    int evaluate () {
        if ((board[0][0] == board[0][1] and board[0][1] == board[0][2] and board[0][1] != 'v') or  
            (board[0][0] == board[1][1] and board[1][1] == board[2][2] and board[1][1] != 'v') or
            (board[0][0] == board[1][0] and board[1][0] == board[2][0] and board[1][0] != 'v') or
            (board[1][0] == board[1][1] and board[1][1] == board[1][2] and board[1][1] != 'v') or
            (board[0][1] == board[1][1] and board[1][1] == board[2][1] and board[1][1] != 'v') or
            (board[2][0] == board[2][1] and board[2][1] == board[2][2] and board[2][1] != 'v') or
            (board[0][2] == board[1][2] and board[1][2] == board[2][2] and board[1][2] != 'v') or
            (board[0][2] == board[1][1] and board[1][1] == board[2][0] and board[1][1] != 'v')) {
                if (isPlayerOne) return 1;
                else return -1;
            }
            return 0;
    }
    int minimax (int depth, bool PlayerOneTurn) {
        int score = evaluate();
        if (score == 1 or score == -1) return score;
        if (drawCheck()) return 0;
        if (PlayerOneTurn) {
            int bestMove = INT_MIN;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == 'v') {
                        board[i][j] = 'X';
                        bestMove = max(bestMove, minimax(depth + 1, !PlayerOneTurn));
                        board[i][j] = 'v';
                    }
                }
            }
            return bestMove;
        } else {
            int bestMove = INT_MAX;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == 'v') {
                        board[i][j] = 'O';
                        bestMove = min(bestMove, minimax(depth + 1, !PlayerOneTurn));
                        board[i][j] = 'v';
                    }
                }
            }
            return bestMove;
        }
    }
    // optimal move chosen by AI
    void findBestMove () {
        int r, c;
        bool found = false;
        vector<pair<int, int>> one, zero;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'v') {
                    board[i][j] = 'O';
                    int valueByAI = minimax(0, true);
                    board[i][j] = 'v';
                    if (valueByAI == -1) {
                        board[i][j] = 'O';
                        found = true;
                        break;
                    } else if (valueByAI == 0) {
                        zero.push_back({i, j});
                    } else {
                        one.push_back({i, j});
                    }
                }
            }
            if (found) break;
        }
        if (!found) {
            if (zero.size()) {
                pair<int, int> p = zero.back();
                r = p.first, c = p.second;
                board[r][c] = 'O';
            } else {
                pair<int, int> p = one.back();
                r = p.first, c = p.second;
                board[r][c] = 'O';
            }
        }
    }
};

int main() {
    Tic_Tac_toe T;
    while (1) {
        if (T.playerOne()) {
            T.getInput();
            T.boardMark();
        } else {
            T.findBestMove();
        }
        T.displayBoard();
        // if (T.evaluate() == 1 and T.playerOne()) {
        //     cout << "Player 1 wins the game \n";
        //     break;
        // } else if (T.drawCheck()) {
        //     cout << "The game ends in a draw \n";
        //     break;
        // } else if (T.evaluate() == -1 and !T.playerOne()) {
        //     cout << "computer wins the game \n";
        //     break;
        // }
        T.changingTurn();
    }
    return 0;
}