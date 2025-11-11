//Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances for edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        // Distance to itself = 0
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Floyd–Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int ans = -1;
        int minReachable = INT_MAX;

        // Find the city with smallest number of reachable cities
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minReachable) {
                minReachable = count;
                ans = i;
            }
        }

        return ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {2, 3, 4},
        {0, 3, 7}
    };
    int distanceThreshold = 4;

    Solution obj;
    int result = obj.findTheCity(n, edges, distanceThreshold);

    cout << "The city with the smallest number of reachable cities within threshold is: " << result << endl;

    return 0;
}
