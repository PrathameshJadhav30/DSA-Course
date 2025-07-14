// Optimal Approach - Backtracking
//Problem Link: https://www.leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: if target is met
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If index is out of bounds or target is negative
        if (index >= candidates.size() || target < 0)
            return;

        // Include the current candidate
        current.push_back(candidates[index]);
        backtrack(index, candidates, target - candidates[index], current, result);
        current.pop_back(); // backtrack

        // Exclude the current candidate and move to the next
        backtrack(index + 1, candidates, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, candidates, target, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> combinations = sol.combinationSum(candidates, target);

    cout << "All unique combinations that sum to " << target << ":" << endl;
    for (auto& comb : combinations) 
    {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
