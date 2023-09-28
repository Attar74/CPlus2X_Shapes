#include <iostream>
using namespace std;

void DrawBoard(char board[3][3]) {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j <= 18; j++) {
            if(!(i%2)) {
                cout << "-";
            } else if (!(j%6)) {
                cout << "|";
            } else if (!(j%3)) {
                if(board[i/2][j/6] != ' ' && i / 2 < 3 && j/6 < 3)
                {
                    cout << board[i/2][j/6];
                } else {
                    cout << " ";
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

char whosWinner(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for(int i = 0; i < 3; i++) {
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    for(int i = 0; i < 3; i++) {
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][1];
        }
    }

    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[2][2] == board[1][1]) {
        return board [0][0];
    }

    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[2][0] == board[1][1]) {
        return board [1][1];
    }

    return ' ';
}
int main () {
    char board [3][3];

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }
    int counter = 0;
    bool isFirstPayer = true;
    int row;
    int col;
    char winner = ' ';
    while (counter < 9 && winner == ' ') {
        do {
            cout << "Enter valid index, pls \n";
            cin >> row;
            cin >> col;
        } while(row < 0 || row > 2 || col < 0 || col > 2 || board [row][col] != ' ');
        board [row][col] = isFirstPayer ? 'X' : 'O';
        isFirstPayer = !isFirstPayer;
        DrawBoard(board);
        winner = whosWinner(board);
        counter++;
    }
    if(winner == ' ') {
        cout << "Game Over! no winner" << endl;
    }
    else {
        cout << "Player " << winner << " won!!" << endl;
    }
    cout << endl;
    return 0;
}