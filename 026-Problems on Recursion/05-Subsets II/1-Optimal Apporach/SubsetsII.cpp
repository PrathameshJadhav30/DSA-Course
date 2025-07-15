//Optimal Apporach
// Problem Link:https://leetcode.com/problems/subsets-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]){
              continue;
            } 

            current.push_back(nums[i]);
            helper(i + 1, nums, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());  // Important to handle duplicates
        helper(0, nums, current, result);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Unique subsets:" << endl;
    for (auto subset : result) 
    {
        cout << "[";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
