// Optimal Approach - Binary Search
// Problem Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        // Binary search loop
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid is less than next element, we are in increasing part
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1; // Move to the right part
            } else {
                // We are in decreasing part or at peak
                high = mid; // Move to the left part including mid
            }
        }

        // When low == high, we've found the peak index
        return low;
    }
};

int main() {
    vector<int> arr = {0, 10, 5, 2}; 

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr); // Call function

    cout << "Peak index is: " << peakIndex << endl; // Output: 1
    return 0;
}
