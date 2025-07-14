// Brute Force Approach
//Problem Link: https://www.leetcode.com/problems/subsets/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n; // 2^n
        vector<vector<int>> result;

        for (int mask = 0; mask < total; mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = sol.subsets(nums);

    cout << "All subsets (Bitmasking):" << endl;
    for (auto& subset : allSubsets) 
    {
        cout << "[ ";
        for (int val : subset)
            cout << val << " ";
        cout << "]" << endl;
    }

    return 0;
}
