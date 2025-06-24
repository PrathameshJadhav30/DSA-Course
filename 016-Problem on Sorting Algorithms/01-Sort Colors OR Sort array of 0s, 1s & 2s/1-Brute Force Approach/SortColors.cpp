// Brute Force Apporach
// Problem Link: https://leetcode.com/problems/sort-colors/description/
#include <iostream>
#include <vector>
using namespace std;

// Brute Force: Count 0s, 1s, 2s and overwrite array
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count the frequency of 0s, 1s and 2s
        for (int num : nums) 
        {
            if (num == 0){
                count0++;
            } else if (num == 1){
                count1++;
            } 
            else {
                count2++;
            }
        }

        // Overwrite the array
        int index = 0;
        while (count0--){
            nums[index++] = 0;
        }
        while (count1--) {
            nums[index++] = 1;
        }
        while (count2--) {
            nums[index++] = 2;
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted Colors (Brute): ";
    for (int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}