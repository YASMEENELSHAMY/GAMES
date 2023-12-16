
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;
RandomPlayer2::RandomPlayer2(char symbol, int dimension): Player_Four_in_a_row(symbol){
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void RandomPlayer2::get_move(int &x,int& y) {
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
