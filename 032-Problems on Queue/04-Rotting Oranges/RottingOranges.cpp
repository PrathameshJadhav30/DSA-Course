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
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push(make_pair(i, j)); // rotten oranges
                }
                if (visited[i][j] == 1) {
                    countFreshOrange++;
                }
            }
        }

        if (countFreshOrange == 0) return 0;
        if (q.empty()) return -1;

        int minutes = -1;
        vector<pair<int, int>> dirs;
        dirs.push_back(make_pair(1, 0));
        dirs.push_back(make_pair(-1, 0));
        dirs.push_back(make_pair(0, -1));
        dirs.push_back(make_pair(0, 1));

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> cell = q.front();
                q.pop();

                int x = cell.first;
                int y = cell.second;

                for (size_t k = 0; k < dirs.size(); k++) {
                    int dx = dirs[k].first;
                    int dy = dirs[k].second;

                    int i = x + dx;
                    int j = y + dy;

                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;  // make rotten
                        countFreshOrange--;
                        q.push(make_pair(i, j));
                    }
                }
            }
            minutes++;
        }

        return (countFreshOrange == 0) ? minutes : -1;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = sol.orangesRotting(grid);
    cout << "Minimum minutes to rot all oranges: " << result << endl;

    return 0;
}
