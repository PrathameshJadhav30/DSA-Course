//Problem Link: https://leetcode.com/problems/redundant-connection/description/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, depth;

public:
    // Constructor: initializes parent and depth arrays
    DisjointSet(int n) : parent(n), depth(n) {
        depth.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    // Find with path compression
    int getRoot(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = getRoot(parent[x]);
    }

    // Union by rank (depth)
    bool merge(int x, int y) {
        int rootX = getRoot(x), rootY = getRoot(y);
        if (rootX == rootY)
            return false;

        if (depth[rootX] > depth[rootY])
            swap(rootX, rootY);

        parent[rootX] = rootY;

        if (depth[rootX] == depth[rootY])
            depth[rootY]++;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n + 1);

        for (auto& edge : edges) {
            if (!ds.merge(edge[0], edge[1])) {
                return edge; // This edge creates a cycle
            }
        }
        return {};
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int x : vec)
        cout << x << " ";
    cout << "]" << endl;
}

int main() {
    // Example input: A graph that forms a cycle
    // Graph edges = [[1,2],[1,3],[2,3]]
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

    Solution sol;
    vector<int> redundantEdge = sol.findRedundantConnection(edges);

    cout << "Redundant Connection Edge: ";
    printVector(redundantEdge);

    return 0;
}
