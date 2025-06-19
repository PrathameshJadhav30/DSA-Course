// Brute Force Apporach
// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Traverse the array in pairs
        for (int i = 0; i < nums.size() - 1; i += 2) 
        {
            // If current and next elements are not equal,
            // then current is the unique element
            if (nums[i] != nums[i + 1]) 
            {
                return nums[i];
            }
        }
        // If loop ends, last element is the single one
        return nums[nums.size() - 1];
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Unique element (Brute): " << obj.singleNonDuplicate(nums1) << endl; // Output: 2

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Unique element (Brute): " << obj.singleNonDuplicate(nums2) << endl; // Output: 10

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)