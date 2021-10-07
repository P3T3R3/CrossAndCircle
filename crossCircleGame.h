//
// Created by P3T3R3 on 07.10.2021.
//
#include <iostream>

#ifndef CROSSCIRCLEGAME_H
#define CROSSCIRCLEGAME_H


class crossCircleGame {
private:

    char grid[3][3]{};
    bool currentPlayer = 1;
    std::string winnerPlayer{};
    std::string firstPlayer{}, secondPlayer{};
    bool isFinished = false;
public:
    crossCircleGame(std::string first, std::string second) {
        firstPlayer = std::move(first);
        secondPlayer = std::move(second);
        std::cout << "This is a new cross and circle game" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
        do {
            playerTurn();
            printGrid();
            checkGrid();
        } while (!isFinished);
    }

    void playerTurn() {
        int column{}, row{};
        std::cout << "Player " << ((currentPlayer == 1) ? firstPlayer : secondPlayer) << " turn" << std::endl;
        do {
            std::cout << "Enter row:";
            std::cin >> row;
            std::cout << "Enter column:";
            std::cin >> column;
            if (!(column >= 0 && column <= 2 && row >= 0 && row <= 2)) {
                std::cout << "Wrong coordinates, please try again" << std::endl;
                continue;
            }
            if (grid[row][column] != ' ') {
                std::cout << "This field has been already used!" << std::endl;
                row = 3;
                column = 3;
                continue;
            }

        } while (!(column >= 0 && column <= 2 && row >= 0 && row <= 2));
        if (currentPlayer) {
            grid[row][column] = 'X';
            currentPlayer = 0;
        } else {
            grid[row][column] = 'O';
            currentPlayer = 1;
        }
    };

    void checkGrid() {
        char winnerChar;
        if (currentPlayer) {
            winnerChar = 'O';
        } else {
            winnerChar = 'X';
        }
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == winnerChar && grid[i][1] == winnerChar && grid[i][2] == winnerChar) {
                isFinished = true;
            }
            if (grid[0][i] == winnerChar && grid[1][i] == winnerChar && grid[2][i] == winnerChar) {
                isFinished = true;
            }
        }
        if (grid[0][0] == winnerChar && grid[1][1] == winnerChar && grid[2][2] == winnerChar) {
            isFinished = true;
        }
        if (grid[2][0] == winnerChar && grid[1][1] == winnerChar && grid[0][2] == winnerChar) {
            isFinished = true;
        }
        if (isFinished) {
            winnerPlayer = (currentPlayer != 1) ? firstPlayer : secondPlayer;
            std::cout << winnerPlayer << " wins the game as " << winnerChar << std::endl;
        }
    };

    void printGrid() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    };

    std::string getWinner() {
        return winnerPlayer;
    };

};


#endif //CROSSCIRCLEGAME_H
