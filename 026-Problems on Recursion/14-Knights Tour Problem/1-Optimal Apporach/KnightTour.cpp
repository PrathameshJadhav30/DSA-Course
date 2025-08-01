//Optimal Apporach 
//Problem Link: https://leetcode.com/problems/check-knight-tour-configuration/description/
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n); // Stores (row, col) of each move number

        // Map each number to its position
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pos[grid[i][j]] = {i, j};

        // First move must start at (0, 0)
        if (pos[0] != make_pair(0, 0))
            return false;

        // Check knight move validity from step 0 to n*n-2
        for (int k = 1; k < n * n; k++) {
            int x1 = pos[k - 1].first;
            int y1 = pos[k - 1].second;
            int x2 = pos[k].first;
            int y2 = pos[k].second;

            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);

            // Valid knight move: (2,1) or (1,2)
            if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    // Call the function and print result
    bool result = sol.checkValidGrid(grid);

    cout << (result ? "Valid Knight Tour " : "Invalid Knight Tour ") << endl;

    return 0;
}
