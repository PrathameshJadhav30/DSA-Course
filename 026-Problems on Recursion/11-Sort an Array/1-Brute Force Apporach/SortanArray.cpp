// Brute Force Apporach
//Problem Link: https://leetcode.com/problems/sort-an-array/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};  

    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted Array : ";

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
