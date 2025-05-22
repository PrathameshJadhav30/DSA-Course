// Optimal Approach (Single Pass)
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfitOptimal(const vector<int>& prices) {
    int minPrice = INT_MAX; // Initialize to the highest possible value to find the minimum stock price
    int maxProfit = 0;      // Initialize the maximum profit to 0

    // Traverse through each price in the array
    for (int price : prices) 
    {
        if (price < minPrice) {
            minPrice = price; // Update minPrice if a lower price is found
        } 
        else {
            // Calculate profit and update maxProfit if this profit is higher
            maxProfit = max(maxProfit, price - minPrice);
        }
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Initialize stock prices for each day
    cout << "Max Profit : " << maxProfitOptimal(prices) << endl; // Output the maximum profit
}
