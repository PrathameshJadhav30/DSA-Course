// Problem Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth-First Search to detect cycle in a 2D grid
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, char ch, int parRow, int parCol) {
        int m = grid.size(), n = grid[0].size();

        // Direction arrays for 4 directions (up, right, down, left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vis[row][col] = 1; // Mark current cell as visited

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check boundaries and same character
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == ch) {
                if (vis[nrow][ncol] == 0) {
                    // DFS for unvisited neighbor
                    if (dfs(grid, vis, nrow, ncol, ch, row, col))
                        return true;
                }
                // If neighbor is visited and not parent → cycle detected
                else if (nrow != parRow || ncol != parCol) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Check every unvisited cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, grid[i][j], -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};
int main() {
    Solution sol;

    //  input grid
    vector<vector<char>> grid = {
        {'a', 'a', 'a', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };

    cout << "Grid:" << endl;
    for (auto& row : grid) {
        for (auto& ch : row) cout << ch << " ";
        cout << endl;
    }

    bool hasCycle = sol.containsCycle(grid);

    cout << "\nContains Cycle? " << (hasCycle ? "Yes" : "No") << endl;

    return 0;
}
