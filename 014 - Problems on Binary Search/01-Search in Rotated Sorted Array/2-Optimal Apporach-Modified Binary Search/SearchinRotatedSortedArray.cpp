// Optimal Apporach Apporach - Modified Binary Search
// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// Optimal solution: Modified binary search
int searchBinary(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Target found
        if (nums[mid] == target){
            return mid;
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid]) 
        {
            // Check if target is in the left half
            if (nums[left] <= target && target < nums[mid]){
                right = mid - 1; // Search left
            } 
            else
            {
                left = mid + 1;  // Search right
            }
                
        }
        // Otherwise, right half is sorted
        else {
            // Check if target is in the right half
            if (nums[mid] < target && target <= nums[right]){
               left = mid + 1;  // Search right
            }     
            else{
                 right = mid - 1; // Search left
            }
               
        }
    }

    // Target not found
    return -1;
}

int main() {
    // Example input
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // Call binary search function
    int index = searchBinary(nums, target);

    // Output result
    cout << "Result: Index = " << index << endl;

    return 0;
}
