
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;
Four_in_a_row::Four_in_a_row() {
    n_rows =6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Four_in_a_row::update_board(int x,int y, char mark) {
    for (int i = n_rows-1; i >=0 ; --i) {
        if (!(y < 0 || y > 6) && (board[i][y] == 0)) {
            board[i][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    return false;

}
void Four_in_a_row::display_board() {
    for (int i: {0,1,2,3,4,5,6}) {
        cout << "\n|";
        for (int j: {0,1,2,3,4,5,6}) {
            if (i==6){
                cout<<setw(2)<<j<<" |";
                continue;
            }
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------";
    }
    cout << endl;
}
bool Four_in_a_row::is_winner() {
    //check rows
    for (int i:{0,1,2,3,4,5}) {
        for(int j:{0,1,2,3}) {
            if (board[i][j]&&
                (board[i][j] == board[i][j + 1]) &&
                (board[i][j + 1] == board[i][j + 2]) &&
                (board[i][j + 2] == board[i][j + 3])) {
                return true;
            }
        }
    }
    //check columns
    for (int j:{0, 1, 2, 3, 4, 5, 6}) {
        for (int i: {0, 1, 2}) {
            if (board[i][j]&&
                (board[i][j] == board[i + 1][j]) &&
                (board[i + 1][j] == board[i + 2][j]) &&
                ( board[i + 2][j] == board[i + 3][j])) {
                return true;
            }
        }
    }
    // Check diagonals from top-left to bottom-right
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i + 1][j + 1] == board[i + 2][j + 2] &&
                board[i + 2][j + 2] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonals from top-right to bottom-left
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = n_cols - 1; j >= 3; --j) {
            if (board[i][j] != 0 &&
                board[i][j] == board[i + 1][j - 1] &&
                board[i + 1][j - 1] == board[i + 2][j - 2] &&
                board[i + 2][j - 2] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }
    return false;
}
bool Four_in_a_row ::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool Four_in_a_row::game_is_over() {
    return n_moves >= 42;
}
