#include <iostream>
#include "crossCircleGame.h"
using namespace std;


int main() {
    cout << "Welcome to Cross and Circle game" << endl;
    string firstPlayer{}, secondPlayer{};
    cout << "Type first player name" << endl;
    cin >> firstPlayer;
    cout << "Type second player name" << endl;
    cin >> secondPlayer;
    crossCircleGame newGame(firstPlayer, secondPlayer);
    return 0;
}
