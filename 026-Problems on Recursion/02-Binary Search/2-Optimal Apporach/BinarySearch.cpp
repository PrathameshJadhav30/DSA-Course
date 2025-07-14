// Optimal Approach - Binary Search
//Problem Link: https://www.leetcode.com/problems/binary-search/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
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
    cout << "Index of target (Binary Search): " << index << endl;

    return 0;
}
