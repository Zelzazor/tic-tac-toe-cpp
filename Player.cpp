#include <string>
#include "Player.h"
#include "GameBoard.h"
using namespace std;

Player::Player(string name, char tile){
    this->name = name;
    this->tile = tile;
    this->victories = 0;
}

void Player::addVictory(){
    victories++;
}

int Player::getVictories(){
    return victories;
}

string Player::getName(){
    return name;
}

char Player::getTile(){
    return tile;
}

bool Player::makeMove(GameBoard* board, int row, int column){
    if(board->gameboard[row][column] == 'e'){
        board->gameboard[row][column] = getTile();
        return true;
    }
    else{
        return false;
    }
}