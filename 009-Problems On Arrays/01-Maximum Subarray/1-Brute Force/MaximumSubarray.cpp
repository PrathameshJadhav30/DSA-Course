// Brute Force Approach
// Problem link: https://leetcode.com/problems/maximum-subarray/description/
#include<iostream>
#include<vector>
using namespace std;

// Brute Force Approach: O(n^2) time
int maxSubArray(vector<int>& nums){
    int n = nums.size();
    int max_sum = nums[0];  // Initialize with first element of the array

    // Try every possible subarray
    for(int i = 0; i < n; i++){
        int Current_sum = 0;  // Initialize sum for subarray starting at index i
        for(int j = i; j < n; j++){
            Current_sum += nums[j];  // Add current element to current subarray sum
            max_sum = max(max_sum, Current_sum); // Update max_sum if current subarray sum is greater
        }
    }
    return max_sum;  // Return the maximum subarray sum found
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};  // Input array
    cout<<"Maximum SubArray Sum: "<<maxSubArray(nums)<<endl;  // Display result
    return 0;
}
