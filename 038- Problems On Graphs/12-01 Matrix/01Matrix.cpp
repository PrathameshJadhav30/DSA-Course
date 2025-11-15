//Problem Link: https://leetcode.com/problems/01-matrix/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        // Step 1: Push all 0s in queue and mark 1s as INT_MAX
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        // Step 2: BFS from all zeroes
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (auto direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    mat[newRow][newCol] > mat[row][col] + 1) 
                {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return mat;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = sol.updateMatrix(mat);

    cout << "Output Matrix:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
