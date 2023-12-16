// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board {
protected:
   int n_rows, n_cols;
   char** board;
   int  n_moves = 0;

public:
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   virtual bool update_board (int x,int y, char symbol) = 0;
   // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.
   virtual bool is_winner() = 0;
   // Return true if all moves are done and no winner
   virtual bool is_draw() = 0;
   // Display the board and the pieces on it
   virtual void display_board() = 0;
   // Return true if game is over
   virtual bool game_is_over() = 0;
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
   X_O_Board ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool is_draw();
   bool game_is_over();
};

class Pyramid_Board : public Board{
public:
    Pyramid_Board();
    bool update_board (int x,int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();


};


class Four_in_a_row :public Board{
public:
    Four_in_a_row();
    bool update_board (int x,int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();


};
class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        virtual void get_move(int& x,int& y);
        // Give player info as a string
        string to_string();
        // Get symbol used by player
        char get_symbol();
};
class Player_Four_in_a_row : public Player{
public:
    Player_Four_in_a_row(char symbol);
    Player_Four_in_a_row(int order, char symbol);

    void get_move(int& x,int& y);
    string to_string();
    char get_symbol();

};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);
};
class RandomPlayer2: public Player_Four_in_a_row{
protected:
    int dimension;
public:
    RandomPlayer2(char symbol, int dimension);
    void get_move(int& x,int&y);

};

///////////////////////////////////////////
class GameManager {
protected:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager(Board*, Player* playerPtr[2]);
        void run();
        // This method creates board and players
        // It displays board
        // While True
        //   For each player
        //      It takes a valid move as x, y pair (between 0 - 2)
        //      It updates board and displays otit
        //      If winner, declare so and end
        //      If draw, declare so and end

};


#endif
