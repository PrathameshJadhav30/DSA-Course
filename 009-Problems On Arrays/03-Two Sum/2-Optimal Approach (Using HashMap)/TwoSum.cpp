// Optimal Approach (Using HashMap)
// Problem Link: https://leetcode.com/problems/two-sum/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two indices such that their values sum to target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;  // Map number to its index

    for (int i = 0; i < nums.size(); i++) 
    {
        int complement = target - nums[i];  // Needed pair value

        if (numMap.find(complement) != numMap.end()) {
            // Found the pair, return indices
            return {numMap[complement], i};
        }

        // Store current number and index
        numMap[nums[i]] = i;
    }

    return {};  // Return empty vector if no pair found (problem guarantees one)
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
