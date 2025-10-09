//Problem Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
private:
    vector<vector<int>> up; // Binary lifting table
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        // Calculate max power of 2 needed
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        // Initialize table
        up.assign(n, vector<int>(LOG, -1));

        // Set 2^0 = parent
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Fill the table using DP
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1)
                    up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1) return -1; // No ancestor exists
            }
        }
        return node;
    }
};

// Driver code to test the TreeAncestor class
int main() {
    int n = 7;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};

    TreeAncestor* obj = new TreeAncestor(n, parent);

    cout << obj->getKthAncestor(3, 1) << endl; // Output: 1
    cout << obj->getKthAncestor(5, 2) << endl; // Output: 0
    cout << obj->getKthAncestor(6, 3) << endl; // Output: -1

    delete obj;
    return 0;
}
