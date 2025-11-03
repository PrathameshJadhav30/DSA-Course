#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<pair<int,int>> adj[n]; // pair -> (neighbor, weight)

    vector<tuple<int,int,int>> edges = {
        {0,1,4}, {0,2,1}, {1,2,2}, {2,3,5}
    };

    for (auto [u,v,w] : edges) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // undirected
    }

    cout << "Weighted Adjacency List:\n";
    for (int i=0; i<n; i++) {
        cout << i << " -> ";
        for (auto [v,w] : adj[i])
            cout << "(" << v << "," << w << ") ";
        cout << endl;
    }

    return 0;
}
