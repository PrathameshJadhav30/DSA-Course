// Optimal Approach
// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) 
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << "Duplicate number: " << findDuplicate(nums) << endl;
    return 0;
}

