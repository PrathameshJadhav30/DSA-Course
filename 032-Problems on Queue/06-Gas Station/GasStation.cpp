//Problem Link: https://leetcode.com/problems/gas-station/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If tank goes negative, can't start from previous stations
            if (tank < 0) {
                start = i + 1;   // try next station as start
                tank = 0;        // reset tank
            }
        }

        return (totalGas < totalCost) ? -1 : start;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> gas1 = {1,2,3,4,5};
    vector<int> cost1 = {3,4,5,1,2};
    cout << "Output 1: " << sol.canCompleteCircuit(gas1, cost1) << endl;

    // Example 2
    vector<int> gas2 = {2,3,4};
    vector<int> cost2 = {3,4,3};
    cout << "Output 2: " << sol.canCompleteCircuit(gas2, cost2) << endl;

    return 0;
}
