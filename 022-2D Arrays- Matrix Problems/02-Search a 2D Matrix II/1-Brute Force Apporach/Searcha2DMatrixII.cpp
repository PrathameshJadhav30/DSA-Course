// Brute Force Approach
//Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                if (matrix[i][j] == target)
                    return true;
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
    int target = 5;
    Solution obj;
    cout << (obj.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    return 0;
}
// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) as we are not using any extra space except for the input matrix and target variable.
// This approach is straightforward but not efficient for large matrices.