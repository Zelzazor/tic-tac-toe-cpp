#ifndef GAME_H
#define GAME_H
#include "Player.h"

#include "GameBoard.h"

class Game {
    public:
        Game(Player* player1, Player* player2);
        void Begin();
        void Move(int row, int column);
        bool getGameEnded();
        GameBoard getGameBoard();
        Player* getCurrentTurn();
    private:
        Player* turn = NULL;
        Player* player1;
        Player* player2;
        GameBoard board;
        bool gameEnded;
        void doTurn();
        bool checkVictory();
        bool checkTie();
};

#endif