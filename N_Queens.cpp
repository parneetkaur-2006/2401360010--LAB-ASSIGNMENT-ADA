#include <iostream>
#include <vector>
using namespace std;

int N;
int solutionCount = 0;

bool isSafe(vector<vector<int>> &board, int row, int col) {

    // check column
    for(int i = 0; i < row; i++)
        if(board[i][col]) return false;

    // upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j]) return false;

    // upper right diagonal
    for(int i = row, j = col; i >= 0 && j < N; i--, j++)
        if(board[i][j]) return false;

    return true;
}

void printBoard(vector<vector<int>> &board) {
    cout << "Solution " << ++solutionCount << ":\n";

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(vector<vector<int>> &board, int row) {

    if(row == N) {
        printBoard(board);
        return;
    }

    for(int col = 0; col < N; col++) {

        if(isSafe(board, row, col)) {
            board[row][col] = 1;

            solveNQueen(board, row + 1);

            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    cout << "Enter value of N: ";
    cin >> N;

    if(N <= 0) {
        cout << "Invalid input!" << endl;
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));

    solveNQueen(board, 0);

    if(solutionCount == 0) {
        cout << "No solution exists for N = " << N << endl;
    } else {
        cout << "Total Solutions: " << solutionCount << endl;
    }

    return 0;
}
