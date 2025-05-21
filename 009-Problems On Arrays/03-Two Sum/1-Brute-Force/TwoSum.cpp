// Brute Force Approach
// Problem Link: https://leetcode.com/problems/two-sum/description/
#include <iostream>
#include <vector>
using namespace std;

// Function to find two indices whose values sum up to the target
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    // Try every pair of elements
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the pair equals the target
            if (nums[i] + nums[j] == target) {
                return {i, j};  // Return the indices if found
            }
        }
    }

    return {};  // Return empty vector if no pair is found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};  // Input array
    int target = 9;  // Target sum

    vector<int> result = twoSum(nums, target);  // Call function and get result

    // Print result indices
    if (!result.empty()) {
        cout << "Two Sum indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}
