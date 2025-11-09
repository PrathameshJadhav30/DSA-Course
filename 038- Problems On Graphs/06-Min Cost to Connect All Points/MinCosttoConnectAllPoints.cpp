//Problem Link: https://leetcode.com/problems/min-cost-to-connect-all-points/description/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            // Find the node with the smallest distance not yet in MST
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && (u == -1 || minDist[v] < minDist[u])) {
                    u = v;
                }
            }

            inMST[u] = true;
            totalCost += minDist[u];

            // Update distances to other points
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }

        return totalCost;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> points = {
        {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
    };

    int result = sol.minCostConnectPoints(points);
    cout << "Minimum cost to connect all points: " << result << endl;

    return 0;
}
