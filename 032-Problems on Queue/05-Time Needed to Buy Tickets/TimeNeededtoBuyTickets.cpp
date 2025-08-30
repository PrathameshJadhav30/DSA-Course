//Problem Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        
        for (int i = 0; i < n; i++) 
        {
            if (i <= k)
            {
                time += min(tickets[i], tickets[k]);
            } 
            else
            {
                time += min(tickets[i], tickets[k] - 1);
            }
        }
        
        return time;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> tickets = {2, 3, 2}; 
    int k = 2;

    int result = sol.timeRequiredToBuy(tickets, k);
    cout << "Time required for person " << k << " to buy tickets: " << result << endl;

    return 0;
}
