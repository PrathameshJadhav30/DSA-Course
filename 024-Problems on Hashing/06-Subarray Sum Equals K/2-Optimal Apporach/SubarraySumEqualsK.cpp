// Optimal Approach
// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int prefixSum = 0, count = 0;
    // Iterate through the array and calculate the prefix sum
    // For each prefix sum, check if there is a previous prefix sum
    for (int num : nums) 
    {
        prefixSum += num;
        // Check if there is a prefix sum that, when subtracted from the current
        // prefix sum, equals k.
        if (prefixCount.find(prefixSum - k) != prefixCount.end()){
            // If the difference between the current prefix sum and k
            // exists in the map, it means there are subarrays that sum to k.
              count += prefixCount[prefixSum - k];  
        }
        // Increment the count of the current prefix sum in the map
        // This allows us to count how many times this prefix sum has occurred.
        prefixCount[prefixSum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Count: " << subarraySum(nums, k) << endl;
    return 0;
}
