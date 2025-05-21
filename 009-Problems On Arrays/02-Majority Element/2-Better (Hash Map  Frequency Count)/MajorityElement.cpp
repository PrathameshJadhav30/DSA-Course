// Better Approach (Hash Map/Frequency Count)
// Problem Link: https://leetcode.com/problems/majority-element/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find majority using hash map
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;  // Map to store frequency of each element
    int n = nums.size();

    // Traverse the array
    for (int num : nums) {
        freq[num]++;  // Increment frequency count for current number

        // If current number becomes majority, return it
        if (freq[num] > n / 2) {
            return num;
        }
    }

    return -1; // This line won't be reached as problem guarantees a majority element
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};  // Input array
    cout << "Majority Element : " << majorityElement(nums) << endl;  // Print result
    return 0;
}
