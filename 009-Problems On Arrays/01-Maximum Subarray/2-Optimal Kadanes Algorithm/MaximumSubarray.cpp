// Optimal Approach (Kadane’s Algorithm)
// Problem link: https://leetcode.com/problems/maximum-subarray/description/
#include<iostream>
#include<vector>
using namespace std;

// Kadane's Algorithm: O(n) time
int maxsubArray(vector<int>& nums){
    int max_sum = nums[0];  // Initialize max_sum with the first element
    int Current_sum = 0;     // Variable to track current subarray sum

    for(int num: nums){      // Traverse each element in the array
        Current_sum += num;  // Add current element to Current_sum

        max_sum = max(max_sum, Current_sum);  // Update max_sum if needed

        if(Current_sum < 0){  // If current sum becomes negative, reset it to 0
            Current_sum = 0;
        }
    }
    return max_sum;  // Return the maximum subarray sum
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};  // Input array
    cout<<"Maximum Subarray Sum: "<<maxsubArray(nums)<<endl;  // Display result
    return 0;
}
