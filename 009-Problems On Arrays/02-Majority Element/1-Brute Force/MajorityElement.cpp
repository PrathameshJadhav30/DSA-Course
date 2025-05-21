// Brute Force Approach
// Problem Link: https://leetcode.com/problems/majority-element/description/
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int n = nums.size();

    // Loop through each element
    for(int i = 0; i < n; i++){
        int count = 0;  // Count how many times nums[i] appears

        for(int j = 0; j < n; j++){
            if(nums[j] == nums[i]){  // If elements match, increment count
                count++;
            }
        }

        if(count > n/2){  // If count is more than n/2, it's the majority
            return nums[i];
        }
    }
    return -1;  // Return -1 if no majority element (not expected in this problem)
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2,1,1};  // Input array
    cout<<"Majority Element : "<<majorityElement(nums)<<endl;  // Display result
    return 0;
}
