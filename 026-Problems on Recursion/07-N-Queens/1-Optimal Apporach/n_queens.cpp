//Optimal Apporach
//Problem Link:https://leetcode.com/problems/n-queens/description/
#include <iostream>
#include <vector>
#include <functional> 
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);  // row - col + n - 1
        vector<bool> diag2(2 * n - 1, false);  // row + col

        function <void(int)> backtrack = [&](int row) {
            if (row == n) {
                result.push_back(board);
                return;
            }

            for (int col = 0; col < n; col++) {
                if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                    continue;

                board[row][col] = 'Q';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

                backtrack(row + 1);

                board[row][col] = '.';
                cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
            }
        };

        backtrack(0);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> results = sol.solveNQueens(n);

    cout << "All possible solutions for " << n << "-Queens:\n";
    for (auto& board : results) 
    {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}
