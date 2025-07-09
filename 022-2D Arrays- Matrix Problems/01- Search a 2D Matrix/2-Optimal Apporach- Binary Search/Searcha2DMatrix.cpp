// Optimal Approach - Binary Search
//Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
// Optimal Approach - Binary Search in Matrix 74
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            // Convert mid to 2D indices
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target){
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution obj;
    cout << (obj.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;
    return 0;
}
// Time Complexity: O(log(m * n)) where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1) as we are not using any extra space except for the input matrix and target variable.
// This approach is efficient because it treats the 2D matrix as a 1D array.