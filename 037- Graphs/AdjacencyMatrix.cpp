#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Example undirected edges
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}};

    // Fill adjacency matrix
    for (auto e : edges) {
        int u = e.first, v = e.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }

    // Print matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
