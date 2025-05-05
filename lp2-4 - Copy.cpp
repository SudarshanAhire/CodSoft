#include <iostream>
#include <vector>
using namespace std;

#define N 8 // You can change N to any size you want

int board[N][N];
bool rowLookup[N];
bool slashCodeLookup[2 * N - 1];
bool backslashCodeLookup[2 * N - 1];

int slashCode[N][N];
int backslashCode[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

// Function to check if a queen can be placed
bool isSafe(int row, int col) {
    return !rowLookup[row] &&
           !slashCodeLookup[slashCode[row][col]] &&
           !backslashCodeLookup[backslashCode[row][col]];
}

// Recursive utility function to solve N-Queen
bool solveNQueen(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            rowLookup[i] = true;
            slashCodeLookup[slashCode[i][col]] = true;
            backslashCodeLookup[backslashCode[i][col]] = true;

            if (solveNQueen(col + 1))
                return true;

            // Backtrack
            board[i][col] = 0;
            rowLookup[i] = false;
            slashCodeLookup[slashCode[i][col]] = false;
            backslashCodeLookup[backslashCode[i][col]] = false;
        }
    }
    return false;
}

// Initialize diagonal matrices
void initializeDiagonals() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            slashCode[i][j] = i + j;
            backslashCode[i][j] = i - j + N - 1;
        }
    }
}

int main() {
    initializeDiagonals();

    if (solveNQueen(0))
        printBoard();
    else
        cout << "No solution exists" << endl;

    return 0;
}
