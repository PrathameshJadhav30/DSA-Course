// Brute Force Approach 
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int n = prices.size(); // Store the total number of days
    int maxProfit = 0;     // Initialize the maximum profit to 0

    // Try every possible pair of days (i < j)
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            int profit = prices[j] - prices[i]; // Calculate profit if bought on day i and sold on day j
            maxProfit = max(maxProfit, profit); // Update maxProfit if current profit is greater
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Initialize the stock prices for each day
    cout << "Max Profit : " << maxProfit(prices) << endl; // Print the maximum profit that can be earned
}
