// Optimal Approach - Search from Bottom Left or Top Right
//Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

// Optimal - Start from Top Right in Sorted Matrix 240
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) 
        {
            if (matrix[row][col] == target){
                // If the target is found, return true
                return true;
            } 
            else if (matrix[row][col] < target) {
                // Move down if the current element is less than the target
                row++;
            } 
            else {
                // Move left if the current element is greater than the target
                col--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 20;
    Solution obj;
    cout << (obj.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    return 0;
}
// Time Complexity: O(m + n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) as we are not using any extra space except for the input matrix and target variable.
// This approach is efficient because it leverages the sorted properties of the matrix to eliminate rows or columns based on comparisons with the target value.

