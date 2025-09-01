//Problem Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized Josephus formula approach
    int findTheWinner(int n, int k) {
        int winner = 0; // 0-based index
        for (int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1; // convert to 1-based friend index
    }

    // Simulation approach (slower, but intuitive)
    int findTheWinnerSimulation(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() > 1) {
            for (int i = 1; i < k; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop(); // eliminate k-th friend
        }
        return q.front();
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 5, k1 = 2;
    cout << "Winner (n=5, k=2): " << sol.findTheWinner(n1, k1) << endl;

    // Example 2
    int n2 = 6, k2 = 5;
    cout << "Winner (n=6, k=5): " << sol.findTheWinner(n2, k2) << endl;

    // Extra check using simulation
    cout << "Winner by Simulation (n=5, k=2): " << sol.findTheWinnerSimulation(n1, k1) << endl;

    return 0;
}
