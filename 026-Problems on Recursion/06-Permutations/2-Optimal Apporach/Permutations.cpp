// Optimal Apporach
//Problem Link:https://leetcode.com/problems/permutations/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]){
              continue;
            } 

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.permute(nums);

    cout << "All permutations:" << endl;
    for (auto permutation : result) 
    {
        cout << "[";
        for (int val : permutation) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
