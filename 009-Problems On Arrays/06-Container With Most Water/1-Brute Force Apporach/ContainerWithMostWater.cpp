// Brute Force Approach
// Problem Link: https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define a class Solution with a method to calculate the max area
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0; // Initialize the maximum area to 0
        int n = height.size(); // Get the total number of vertical lines

        // Loop through each pair of lines
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                // Find the height of the shorter line between i and j
                int heigths = min(height[i], height[j]);

                // Calculate the width between the two lines
                int width = j - i;

                // Calculate area formed between the two lines
                int area = heigths * width;

                // Update max_area if current area is greater
                max_area = max(max_area, area);
            }
        }

        // Return the maximum area found
        return max_area;
    }
};

int main() {
    // Sample input: heights of vertical lines
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Create object of Solution class
    Solution sol;

    // Call the maxArea method to find maximum water area
    int maxWater = sol.maxArea(height);

    // Output the result
    cout << "Maximum water that can be contained: " << maxWater << endl;

    return 0;
}
