#include <iostream>

using namespace std;

class crossCircleGame {
private:

    char grid[3][3]{};
    bool currentPlayer = 1;
    string winnerPlayer{};
    string firstPlayer{}, secondPlayer{};
    bool isFinished = false;
public:
    crossCircleGame(string first, string second) {
        firstPlayer = std::move(first);
        secondPlayer = std::move(second);
        cout << "This is a new cross and circle game" << endl;
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
        cout << "Player " << ((currentPlayer == 1) ? firstPlayer : secondPlayer) << " turn" << endl;
        do {
            cout << "Enter row:";
            cin >> row;
            cout << "Enter column:";
            cin >> column;
            if (!(column >= 0 && column <= 2 && row >= 0 && row <= 2)) {
                cout << "Wrong coordinates, please try again" << endl;
                continue;
            }
            if (grid[row][column] != ' ') {
                cout << "This field has been already used!" << endl;
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
            cout << winnerPlayer << " wins the game as " << winnerChar << endl;
        }
    };

    void printGrid() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    };
};

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
