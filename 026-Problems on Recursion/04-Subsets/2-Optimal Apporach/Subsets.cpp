// Optimal Approach - Backtracking
//Problem Link: https://www.leetcode.com/problems/subsets/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        // Generate subsets starting from the current index
        // This ensures that we do not include the same element multiple times
        for (int i = index; i < nums.size(); i++) 
        {
            current.push_back(nums[i]);
            // Recur to generate subsets including the current element
            // This allows us to explore all combinations of elements
            helper(i + 1, nums, current, result);
            // Backtrack: remove the last element added
            // This allows us to explore subsets without the last added element
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        helper(0, nums, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = sol.subsets(nums);

    cout << "All subsets (Backtracking):" << endl;
    for (auto& subset : allSubsets) 
    {
        cout << "[ ";
        for (int val : subset)
            cout << val << " ";
        cout << "]" << endl;
    }

    return 0;
}
