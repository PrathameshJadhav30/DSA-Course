// Optimal Solution - Binary Search
// Problem Link:  https://www.spoj.com/problems/AGGRCOW/
#include <bits/stdc++.h>
using namespace std;

// Helper function to check if we can place all cows with at least 'minDist' distance apart
bool isFeasible(vector<int>& stalls, int cows, int minDist) {
    int count = 1; // Place the first cow
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            // If we have placed all cows, return true
            if (count == cows){
                return true; // All cows are placed successfully
            } 
        }
    }

    return false;
}

// Main function to perform binary search on the answer
int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(stalls, cows, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    // Static input
    int t = 1;
    int n = 5, c = 3;
    vector<int> stalls = {1, 2, 8, 4, 9};

    for (int test = 0; test < t; test++) {
        cout << "Largest minimum distance: " << aggressiveCows(stalls, c) << endl;
    }

    return 0;
}
// Time Complexity: O(N log D), where N is the number of stalls and D is the distance between the first and last stall.
// Space Complexity: O(1), as we are using a constant amount of extra space.