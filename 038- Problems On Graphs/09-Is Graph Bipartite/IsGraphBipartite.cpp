//Problem Link: https://leetcode.com/problems/is-graph-bipartite/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if a graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored, 0 and 1 are two colors

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // not yet visited
                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }

private:
    // DFS function to color nodes alternately
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = c; // assign color
        for (int nei : graph[node]) {
            if (color[nei] == -1) {
                // color neighbor with opposite color
                if (!dfs(nei, 1 - c, color, graph))
                    return false;
            } 
            // if neighbor has same color, not bipartite
            else if (color[nei] == color[node]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Example: Graph with 4 nodes
    // 0 connected to 1,3
    // 1 connected to 0,2
    // 2 connected to 1,3
    // 3 connected to 0,2
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    Solution obj;
    bool result = obj.isBipartite(graph);

    //  Output
    if (result)
        cout << "Graph is Bipartite " << endl;
    else
        cout << "Graph is NOT Bipartite " << endl;

    return 0;
}
