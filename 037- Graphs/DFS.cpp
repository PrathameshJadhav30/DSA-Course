#include <bits/stdc++.h>
using namespace std;

void DFSUtil(int node, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;
    cout << node << " ";

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor])
            DFSUtil(neighbor, adj, visited);
    }
}

int main() {
    int n = 6;
    vector<int> adj[n];
    vector<pair<int, int>> edges = {{0,1},{0,2},{1,3},{2,4},{3,5}};

    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> visited(n, 0);
    cout << "DFS Traversal: ";
    DFSUtil(0, adj, visited);
    return 0;
}
