// Optimal Approach - Two-Pointer
// Problem Link: https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class containing the solution method
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // Initialize left pointer at the beginning
        int right = height.size() - 1; // Initialize right pointer at the end
        int max_area = 0; // Store the maximum area found

        // Loop until the two pointers meet
        while (left < right) {
            // Find the shorter height between left and right
            int heights = min(height[left], height[right]);

            // Calculate the width between the two lines
            int width = right - left;

            // Calculate the current area
            int area = heights * width;

            // Update the maximum area if current is greater
            max_area = max(max_area, area);

            // Move the pointer with the smaller height inward
            if (height[left] < height[right]) 
            {
                left++; // Move left pointer to the right
            } 
            else 
            {
                right--; // Move right pointer to the left
            }
        }

        // Return the maximum area found
        return max_area;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Sample input of heights

    Solution sol; // Create object of Solution class
    int maxWater = sol.maxArea(height); // Get maximum area using two-pointer approach

    cout << "Maximum water that can be contained: " << maxWater << endl; // Print result

    return 0;
}
