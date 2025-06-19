// Optimal Apporach - Binary Search
// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 2;  // we compare nums[mid] with nums[mid + 1]

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            // Ensure mid is even to compare with mid+1
            if (mid % 2 == 1){
                mid--;  // If mid is odd, decrement it to make it even
            } 
            // Check if the pair is valid
            // A valid pair means nums[mid] should be equal to nums[mid + 1]
            // If pair is valid, move to the right half
            if (nums[mid] == nums[mid + 1]) 
            {
                low = mid + 2;
            } else {
                // Pair is broken, move to the left half
                high = mid - 1;
            }
        }

        // After the loop, low will point to the single element
        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Unique element (Optimal): " << obj.singleNonDuplicate(nums1) << endl; // Output: 2

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "Unique element (Optimal): " << obj.singleNonDuplicate(nums2) << endl; // Output: 10

    return 0;
}
// Time Complexity: O(log n)
// Space Complexity: O(1)