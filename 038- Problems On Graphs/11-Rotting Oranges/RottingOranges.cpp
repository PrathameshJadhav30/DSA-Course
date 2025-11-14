//Problem Link: https://leetcode.com/problems/rotting-oranges/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited = grid;
        queue<pair<int, int>> q;

        int countFreshOrange = 0;

        // Push all rotten oranges to queue and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push({i, j});
                }
                if (visited[i][j] == 1) {
                    countFreshOrange++;
                }
            }
        }

        // No fresh oranges → 0 minutes
        if (countFreshOrange == 0)
            return 0;
        
        // Rotten oranges not present but fresh exist → impossible
        if (q.empty())
            return -1;

        int minutes = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [dx, dy] : dirs) {
                    int i = x + dx;
                    int j = y + dy;

                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        countFreshOrange--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }

        return (countFreshOrange == 0) ? minutes : -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);

    cout << "Minutes to rot all oranges = " << result << endl;

    return 0;
}
