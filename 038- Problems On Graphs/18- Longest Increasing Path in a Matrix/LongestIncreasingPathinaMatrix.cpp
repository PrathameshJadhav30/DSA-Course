// Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> A;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(int x, int y) {
        // Already computed?
        if (dp[x][y] != -1) return dp[x][y];

        int best = 1; // minimum path length is 1 (the cell itself)

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] > A[x][y]) {
                best = max(best, 1 + dfs(nx, ny));
            }
        }

        return dp[x][y] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        A = matrix;
        n = A.size();
        m = A[0].size();
        dp.assign(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution sol;
    cout << sol.longestIncreasingPath(matrix) << endl;  
    return 0;
}
