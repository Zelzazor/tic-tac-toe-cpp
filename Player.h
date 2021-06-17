#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "GameBoard.h"

using namespace std;
class Player {
    public:
        Player(string name, char tile);
        string getName();
        char getTile();
        int getVictories();
        bool makeMove(GameBoard* board, int row, int column);
        void addVictory();
    private:
        string name;
        int victories;
        char tile;

};

#endif