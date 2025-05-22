// Better Approach (Prefix Minimum Array)
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfitPrefixMin(const vector<int>& prices) {
    int n = prices.size(); // Store the total number of days

    if (n == 0) {
        return 0; // If there are no prices, return 0 profit
    } 

    vector<int> minPrice(n);        // Create an array to store the minimum price up to each day
    minPrice[0] = prices[0];        // Initialize the first day's minimum price as the first price

    // Fill the prefix minimum array
    for (int i = 1; i < n; i++) 
    {
        // Update minimum price so far up to day i
        minPrice[i] = min(minPrice[i - 1], prices[i]);
    }

    int maxProfit = 0; // Initialize the maximum profit to 0

    // Calculate the maximum profit using prefix minimum values
    for (int i = 1; i < n; i++) 
    {
        // Compare current profit with maxProfit and update if higher
        maxProfit = max(maxProfit, prices[i] - minPrice[i - 1]);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Initialize stock prices for each day
    cout << "Max Profit : " << maxProfitPrefixMin(prices) << endl; // Output the maximum profit
}
