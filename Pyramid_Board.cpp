#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
Pyramid_Board::Pyramid_Board() {
    n_rows = 3;
    n_cols=5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramid_Board::update_board (int x, int y, char mark){
    // Only update if move is valid

    if (!(x < 0||  x > 2 || y < 0 || y > 4) && (board[x][y] == 0)) {

        if(x==0&&y!=0){
            return false;
        }

        if(x==1&&y>2){
            return false;
        }
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
    return false;
}


void Pyramid_Board::display_board() {

    for (int i: {0,1,2}) {

        if(i==0)
        {
            cout << setw(2) <<"                 | (0,0)"<<board[0][0]<<" |";
            cout << "\n---------------------------------------------";
        }



        if(i==1)
        {
            cout<<"         ";
            for(int j=0;j<=2;j++) {
                cout<<" (" << i << "," << j << ")";
                cout   << board[i][j] << " |";

            }
            cout << "\n---------------------------------------------";
        }




        if(i==2)
        {
            for(int j=0;j<=4;j++) {
                cout << " (" << i << "," << j << ")";
                cout <<  board[i][j] << " |";
            }
            cout << "\n---------------------------------------------";
        }


        cout << endl;
    }
}


// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Pyramid_Board::is_winner() {
    char row_win[4], col_win[1], diag_win[2];
    for (int i:{1,2}) {
        if(i==1) {
            row_win[0] = board[1][0] & board[1][1] & board[1][2];
        }
        if(i==2) {
            row_win[1] = board[2][0] & board[2][1]  & board[2][2] ;
            row_win[2]= board[2][1]& board[2][2] & board[2][3];
            row_win[3]= board[2][2] & board[2][3] & board[2][4];
        }

    }

    col_win[0] = board[0][0] & board[1][1] & board[2][2];


    diag_win[0] = board[0][0] & board[1][2] & board[2][4];
    diag_win[1] = board[0][0] & board[1][0] & board[2][0];


    if(row_win[0] && (row_win[0] == board[1][0]))
    {return true;}
    if(row_win[1] && (row_win[1] == board[2][0]))
    {return true;}
    if(row_win[2] && (row_win[2] == board[2][1]))
    {return true;}
    if(row_win[3] && (row_win[3] == board[2][2]))
    {return true;}


    if( col_win[0] && (col_win[0] == board[0][0])){return true;}
    if (diag_win[0] && (diag_win[0] == board[0][0]))
    {return true;}

    if (diag_win[1] && (diag_win[1] == board[0][0]))
    {return true;}


    return false;
}
bool Pyramid_Board::is_draw() {
        return (n_moves == 9 && !is_winner());
    }
    bool Pyramid_Board::game_is_over () {
        return n_moves >= 9;
    }


