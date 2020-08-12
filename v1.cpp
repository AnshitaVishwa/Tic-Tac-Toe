#include<bits/stdc++.h>
using namespace std;

class Tic_Tac_toe {
private:
    int board[3][3];
public:
    Tic_Tac_toe () {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = -1;
            }
        }
    }
    void displayBoard () {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == -1) {
                    cout << "    ";
                } else {
                    cout << "   " << board[i][j] << "   ";
                }
                if(j != 2) cout << "|";
            }
            if (i != 2) cout << "\n-------------------------\n";
        }
    }
};

int main() {
    Tic_Tac_toe t1;
    t1.displayBoard();
    return 0;
}