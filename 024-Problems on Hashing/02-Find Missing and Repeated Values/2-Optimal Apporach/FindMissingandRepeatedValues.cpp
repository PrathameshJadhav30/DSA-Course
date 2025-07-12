// Optimal Approach
//Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    int total = n * n;
    vector<int> freq(total + 1, 0);
    int sum_actual = 0;
    // Count occurrences of each number in the grid
    for (auto& row : grid) 
    {
        for (int num : row) 
        {
            freq[num]++;
            sum_actual += num;
        }
    }

    int repeated = -1, missing = -1;
    // The sum of numbers from 1 to n*n is given by the formula n*(n+1)/2
    int sum_expected = (total * (total + 1)) / 2;
    // The expected sum of numbers from 1 to n*n
    // is given by the formula n*(n+1)/2, where n is the
    for (int i = 1; i <= total; i++) 
    {
        if (freq[i] == 2){
            repeated = i;
        }
        if (freq[i] == 0){
            // The missing number is the one that is not counted
            // in the frequency array, which means it was never seen
            // in the grid.
            missing = i;
        } 
    }

    // Alternative calculation using math (optional):
    // missing = repeated - (sum_actual - sum_expected);

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> result = findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}
