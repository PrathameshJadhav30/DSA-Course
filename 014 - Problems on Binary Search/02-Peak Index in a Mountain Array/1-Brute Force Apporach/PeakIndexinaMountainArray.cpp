// Brute Force Approach - Linear Search
// Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Loop through array from index 1 to n-2
        for (int i = 1; i < arr.size() - 1; i++) {
            // Check if current element is greater than its neighbors
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i; // Peak found
            }
        }
        return -1; // Should never reach here for valid mountain array
    }
};

int main() {
    vector<int> arr = {0, 10, 5, 2}; 

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr); // Call function

    cout << "Peak index is: " << peakIndex << endl; // Output: 1
    return 0;
}
