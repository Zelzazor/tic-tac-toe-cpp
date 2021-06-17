#include "Player.h"
#include "GameBoard.h"
#include "Game.h"
#include <iostream>

using namespace std;


Game::Game(Player* player1, Player* player2){
    this->player1 = player1;
    this->player2 = player2;
    this->gameEnded = false;
}

void Game::Begin(){
    gameEnded = false;
    doTurn();
}

Player* Game::getCurrentTurn(){
    return turn;
}

void Game::doTurn(){
    if(turn == NULL){
        turn = player1;
    }
    else if(turn->getName() == player1->getName()){
        turn = player2;
    }
    else{
        turn = player1;
    }
}

bool Game::getGameEnded(){
    return gameEnded;
}

void Game::Move(int row, int column){
    bool moveMade = turn->makeMove(&board, row, column);

    if(moveMade){
        if(checkVictory()){
            gameEnded = true;
            cout << turn->getName() << " ha ganado!" << endl;
        }
        else if(checkTie()){
            gameEnded = true;
            cout << "Es un empate!" << endl;
        }
        else{
            doTurn();
        }
    }
    else{
        cout << "Celda ya ocupada. Intenta en una celda diferente." << endl;
    }
}

bool Game::checkVictory(){
    for(int i = 0; i < 3; i++){
        if (board.gameboard[i][0] == board.gameboard[i][1] && board.gameboard[i][1] == board.gameboard[i][2] && board.gameboard[i][0] != 'e') {
                return true;
        }
        if (board.gameboard[0][i] == board.gameboard[1][i] && board.gameboard[1][i] == board.gameboard[2][i] && board.gameboard[0][i] != 'e') {
                return true;
        }
    }
    if (board.gameboard[0][0] == board.gameboard[1][1] && board.gameboard[1][1] == board.gameboard[2][2] && board.gameboard[0][0] != 'e') {
            return true;
    }
    if (board.gameboard[0][2] == board.gameboard[1][1] && board.gameboard[1][1] == board.gameboard[2][0] && board.gameboard[0][2] != 'e') {
            return true;
    }

    return false;
}

bool Game::checkTie(){
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.gameboard[i][j] == 'e') {
                    return false;
                }
            }
        }
    return true;
}

GameBoard Game::getGameBoard(){
    return board;
}