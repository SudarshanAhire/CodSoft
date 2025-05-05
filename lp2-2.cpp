#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const char HUMAN = 'X';
const char COMPUTER = 'O';
const char EMPTY = ' ';

// Print the current board
void printBoard(vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if (i % 3 != 2) cout << "|";
        if (i % 3 == 2 && i != 8) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Check winning condition
char checkWinner(vector<char>& board) {
    int win[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}              // diagonals
    };

    for (auto& line : win) {
        if (board[line[0]] != EMPTY &&
            board[line[0]] == board[line[1]] &&
            board[line[1]] == board[line[2]]) {
            return board[line[0]];
        }
    }

    return EMPTY;
}

// Heuristic function: +10 for computer win, -10 for human win, 0 for draw/ongoing
int evaluate(vector<char>& board) {
    char winner = checkWinner(board);
    if (winner == COMPUTER) return +10;
    if (winner == HUMAN) return -10;
    return 0;
}

// Check if any moves are left
bool isMovesLeft(vector<char>& board) {
    for (char c : board) {
        if (c == EMPTY) return true;
    }
    return false;
}

// Minimax with A* style scoring (f = g + h)
int minimax(vector<char>& board, int depth, bool isMax) {
    int score = evaluate(board);
    if (score == 10 || score == -10) return score - depth; // f = g + h
    if (!isMovesLeft(board)) return 0;

    if (isMax) {
        int best = numeric_limits<int>::min();
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = COMPUTER;
                best = max(best, minimax(board, depth + 1, false));
                board[i] = EMPTY;
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = HUMAN;
                best = min(best, minimax(board, depth + 1, true));
                board[i] = EMPTY;
            }
        }
        return best;
    }
}

// Find the best move using minimax
int findBestMove(vector<char>& board) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            board[i] = COMPUTER;
            int moveVal = minimax(board, 0, false);
            board[i] = EMPTY;
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

// Driver function
int main() {
    vector<char> board(9, EMPTY);
    cout << "Tic Tac Toe - A* Based Computer Player\n";
    cout << "You are 'X', Computer is 'O'\n";
    printBoard(board);

    while (true) {
        int move;
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--;

        if (move < 0 || move >= 9 || board[move] != EMPTY) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = HUMAN;
        printBoard(board);

        if (checkWinner(board) == HUMAN) {
            cout << "You win!\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }

        int compMove = findBestMove(board);
        board[compMove] = COMPUTER;
        cout << "Computer plays at position " << (compMove + 1) << "\n";
        printBoard(board);

        if (checkWinner(board) == COMPUTER) {
            cout << "Computer wins!\n";
            break;
        }
        if (!isMovesLeft(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
