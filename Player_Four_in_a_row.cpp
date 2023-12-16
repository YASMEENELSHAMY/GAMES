
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
Player_Four_in_a_row::Player_Four_in_a_row(char symbol) : Player(symbol){}
Player_Four_in_a_row::Player_Four_in_a_row(int order,char symbol): Player(order,symbol) {}
void Player_Four_in_a_row::get_move(int& x,int& y) {
    cout << "\nPlease enter the column number: ";
    cin >> y;
}
string Player_Four_in_a_row::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player_Four_in_a_row::get_symbol() {
    return symbol;
}
