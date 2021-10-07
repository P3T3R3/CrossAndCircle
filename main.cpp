#include <iostream>
#include "crossCircleGame.h"
using namespace std;


int main() {
    cout << "Welcome to Cross and Circle game" << endl;
    string firstPlayer{}, secondPlayer{};
    cout << "Type first player name (will play as X)" << endl;
    cin >> firstPlayer;
    cout << "Type second player name (will play as O)" << endl;
    cin >> secondPlayer;
    crossCircleGame newGame(firstPlayer, secondPlayer);
    newGame.startGame();
    return 0;
}
