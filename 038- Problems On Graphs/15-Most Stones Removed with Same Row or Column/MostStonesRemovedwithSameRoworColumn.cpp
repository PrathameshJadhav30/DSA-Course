// Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int removeStones(vector<vector<int>>& stones) {
        // Union rows and columns
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; // Offset columns to avoid overlap
            unite(row, col);
        }

        unordered_set<int> unique_roots;

        // Count distinct connected components
        for (auto& stone : stones) {
            unique_roots.insert(find(stone[0]));
        }

        // Maximum removable stones = total stones - number of components
        return stones.size() - unique_roots.size();
    }
};

int main() {
    Solution sol;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    int result = sol.removeStones(stones);

    cout << "Number of removable stones: " << result << endl;

    return 0;
}
