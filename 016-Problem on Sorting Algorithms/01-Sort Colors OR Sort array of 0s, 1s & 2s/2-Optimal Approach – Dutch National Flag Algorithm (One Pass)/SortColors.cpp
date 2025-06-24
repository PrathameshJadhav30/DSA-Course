// Optimal Apporach- Dutch National Flag Algorithm (One Pass)
// This algorithm sorts an array containing only 0s, 1s, and 2
// Problem Link:  https://leetcode.com/problems/sort-colors/description/
#include <iostream>
#include <vector>
using namespace std;

// Optimal One Pass: DNF Algorithm using low, mid, high
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        // Traverse through the array
        while (mid <= high) 
        {
            if (nums[mid] == 0) // place 0 at low
            {
                swap(nums[low++], nums[mid++]); // place 0 at low
            } 
            else if (nums[mid] == 1) // leave 1 in the middle
            {
                mid++; // leave 1 as it is
            } 
            else  // nums[mid] == 2, place 2 at high
            {
                swap(nums[mid], nums[high--]); // place 2 at high
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted Colors (Optimal): ";
    for (int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}