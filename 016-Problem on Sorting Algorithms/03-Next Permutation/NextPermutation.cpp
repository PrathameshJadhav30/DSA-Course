// Optimal Apporach - Next Permutation
//Problem Link: https://leetcode.com/problems/next-permutation/description/
#include <iostream>
#include <vector>
#include <algorithm> // for reverse()
using namespace std;

// Optimal Solution: Single pass in-place
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) 
        {
            i--;
        }

        // Step 2: If such element found, find next greater and swap
        if (i >= 0) 
        {
            int j = n - 1;
            while (nums[j] <= nums[i]) 
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix starting from i+1
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> nums = {1, 2, 3}; 

    cout << "Original: ";
    for (int num : nums){
      cout << num << " ";
    } 
    cout << endl;

    Solution Sol;
    Sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums){
      cout << num << " ";
    } 
    cout << endl;

    return 0;
}
