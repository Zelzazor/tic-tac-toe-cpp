#include "Game.h"
#include "Player.h"
#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

void Show(GameBoard* tablero){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero->gameboard[i][j] == ' '){
                cout << "  ";
            }
            else{
                cout << tablero->gameboard[i][j] << " ";
            }
            
        }
        cout << endl;
    } 
}

int main() {
    string nombre_jugador_1, nombre_jugador_2;
    cout << "Escriba su nombre, Jugador 1: ";
    cin >> nombre_jugador_1;
    cout << "Escriba su nombre, Jugador 2: ";
    cin >> nombre_jugador_2;

    Player player1(nombre_jugador_1, 'x');
    Player player2(nombre_jugador_2, 'o');

    Game juego(&player1, &player2);
    juego.Begin();

    
    do{
        GameBoard tablero = juego.getGameBoard();
        int fila, columna = 0;
        Show(&tablero);
        cout << "Digite la fila, " << juego.getCurrentTurn()->getName()<<": ";
        cin >> fila;
        cout << "Digite la columna, " << juego.getCurrentTurn()->getName()<<": ";
        cin >> columna;
        juego.Move(fila-1, columna-1);
    }while(!juego.getGameEnded());

    GameBoard tablero = juego.getGameBoard();
    Show(&tablero);

    return 0;
}