#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; // Number of vertices
    vector<int> adjList[n];

    // Example edges
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};

    for (auto e : edges) {
        int u = e.first, v = e.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected
    }

    // Print adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto j : adjList[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
