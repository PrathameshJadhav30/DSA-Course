// Brute Force Apporach - Linear Search
// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// Brute-force solution: Linear search
int search(vector<int>& nums, int target) {
    // Loop through the array
    for (int i = 0; i < nums.size(); i++) 
    {
        // If target found, return its index
        if (nums[i] == target){
            return i;
        }
            
    }
    // If not found, return -1
    return -1;
}

int main() {
    // Example input
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    // Call search function
    int index = search(nums, target);

    // Output result
    cout << "Result: Index = " << index << endl;

    return 0;
}
