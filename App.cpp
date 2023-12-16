
// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int n;
    cout<<"1-\tX_O-Game\n"
          "2-\tPyramid_Game\n"
          "3-\tFour_in_a_row_Game\n"
          "4-\tExit\n";
    cout<<"ENTER THE NUMBER OF GAME OR 0 TO EXIT: \n";
    cin>>n;

    int choice;
    Player* players[2];
    if (n==3)
        players[0] = new Player_Four_in_a_row (1, 'x');
    else
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1) {
        if (n == 3)
            players[1] = new Player_Four_in_a_row (2, 'o');
        else
            players[1] = new Player(2, 'o');
    }
    else
        if(n==3)
            players[1] = new RandomPlayer2 ('o', 7);
        else //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);
    while (n!=0){
        if (n==1){
            GameManager x_o_game (new X_O_Board(), players);
            x_o_game.run();
            system ("pause");
        }
        if(n==2){
            GameManager Pyramid (new Pyramid_Board(), players);
            Pyramid.run();
            system ("pause");
        }
        if (n==3){
                GameManager Four(new Four_in_a_row(), players);
                Four.run();
                system ("pause");
        }
        cout<<"ENTER THE NUMBER OF GAME OR 0 TO EXIT: \n";
        cin>>n;
    }


}
