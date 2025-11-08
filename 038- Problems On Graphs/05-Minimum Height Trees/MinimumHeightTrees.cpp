// Problem Link: https://leetcode.com/problems/minimum-height-trees/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // Base case: single node

        // Build adjacency list and degree array
        vector<list<int>> adjacency_list(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Queue for leaf nodes (degree == 1)
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1)
                leaves.push(i);
        }

        int remainingNodes = n;

        // Trim leaves layer by layer until <= 2 nodes remain
        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;

            for (int i = 0; i < leavesCount; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adjacency_list[leaf]) {
                    if (--degree[neighbor] == 1)
                        leaves.push(neighbor);
                }
            }
        }

        // Remaining nodes are roots of Minimum Height Trees
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
int main() {
    Solution sol;

    // Example input
    int n = 6;
    vector<vector<int>> edges = {
        {0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}
    };

    vector<int> result = sol.findMinHeightTrees(n, edges);

    cout << "Roots of Minimum Height Trees: ";
    for (int node : result) cout << node << " ";
    cout << endl;

    return 0;
}
