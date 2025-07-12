// Brute Force Approach
//Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int total = n * n;
    vector<int> count(total + 1, 0);
    // Count occurrences of each number in the grid
    // The numbers should be in the range 1 to n*n
    for (auto& row : grid) 
    {
        for (int num : row) 
        {
            count[num]++;
        }
    }

    int repeated = -1, missing = -1;
    // Find the repeated and missing values
    // The numbers should be in the range 1 to n*n
    for (int i = 1; i <= total; i++) 
    {
        if (count[i] == 2) 
        {
            repeated = i;
        }
        if (count[i] == 0) 
        {
            missing = i;
        }
    }

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> result = findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}
