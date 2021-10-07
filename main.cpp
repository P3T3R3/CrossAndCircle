#include <iostream>

using namespace std;

class crossCircleGame {
private:
    char grid[3][3]{};
    bool player = 1;
    bool isFinished = false;
public:
    crossCircleGame() {
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
        cout << "Player " << player << " turn" << endl;
        do {
            cout << "Enter row:";
            cin >> row;
            cout << "Enter column:";
            cin >> column;
            if (grid[row][column] != ' ') {
                cout << "This position is not empty!" << endl;
                row = 3;
                column = 3;
                continue;
            }
            if (!(column >= 0 && column <= 2 && row >= 0 && row <= 2))
                cout << "Wrong coordinates, please try again" << endl;
        } while (!(column >= 0 && column <= 2 && row >= 0 && row <= 2));
        if (player) {
            grid[row][column] = 'X';
            player = 0;
        } else {
            grid[row][column] = 'O';
            player = 1;
        }
    };

    void checkGrid() {
        cout << "Checking grid..." << endl;
        char winnerChar;
        if (!player) {
            winnerChar = 'X';
        } else {
            winnerChar = 'O';
        }
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == winnerChar && grid[i][1] == winnerChar && grid[i][2] == winnerChar) {
                cout << winnerChar << " wins";
                isFinished = true;
            }
            if (grid[0][i] == winnerChar && grid[1][i] == winnerChar && grid[2][i] == winnerChar) {
                cout << winnerChar << " wins";
                isFinished = true;
            }
        };
        if (grid[0][0] == winnerChar && grid[1][1] == winnerChar && grid[2][2] == winnerChar) {
            cout << winnerChar << " wins";
            isFinished = true;
        }
        if (grid[2][0] == winnerChar && grid[1][1] == winnerChar && grid[0][2] == winnerChar) {
            cout << winnerChar << " wins";
            isFinished = true;
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
    cout << "Cross and Circle" << endl;
    crossCircleGame newGame;

    return 0;
}
