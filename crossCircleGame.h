//
// Created by P3T3R3 on 07.10.2021.
//
#include <iostream>

#ifndef CROSSCIRCLEGAME_H
#define CROSSCIRCLEGAME_H

class crossCircleGame {
private:

    char grid[3][3]{};
    bool currentPlayer = 1; //because is only 2 players, we use bool
    std::string winnerPlayer{};
    std::string firstPlayer{}, secondPlayer{};
public:
    static int numGames;
    bool isFinished = false;

    crossCircleGame(std::string first, std::string second);

    void startGame();

    void playerTurn();

    void checkGameState();

    void printGrid(); //prints state of grid

    void restartGame();

    std::string getWinner();;

};


#endif //CROSSCIRCLEGAME_H
