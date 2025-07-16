//Optimal Apporach
//Problem Link:https://leetcode.com/problems/sudoku-solver/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch || board[i][col] == ch) return false;
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if(board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    sol.solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    for (auto& row : board) 
    {
        for (char c : row) {
            cout << c << " ";
        }
        cout << "\n";
    }
    return 0;
}
