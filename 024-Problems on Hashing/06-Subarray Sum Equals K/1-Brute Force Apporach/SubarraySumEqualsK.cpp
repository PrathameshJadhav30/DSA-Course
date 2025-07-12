// Brute Force Approach
// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count = 0, n = nums.size();

    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        for (int j = i; j < n; j++) 
        {
            sum += nums[j];
            if (sum == k){
                // If the sum of the subarray from index i to j equals k,
                // increment the count.
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Count: " << subarraySum(nums, k) << endl;
    return 0;
}
