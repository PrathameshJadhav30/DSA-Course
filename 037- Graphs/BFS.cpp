#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<int> adj[], int n) {
    vector<int> visited(n, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
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

    BFS(0, adj, n);
    return 0;
}
