// Brute Force Approach
//Problem Link: https://www.leetcode.com/problems/binary-search/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target;

    cout << "Enter target to search: ";
    cin >> target;

    int index = sol.search(nums, target);
    cout << "Index of target (Linear Search): " << index << endl;

    return 0;
}
