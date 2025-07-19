// Optimal Apporach
//Problem Link: https://leetcode.com/problems/sort-an-array/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1;
        vector<int> temp;

        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j])
              temp.push_back(nums[i++]);
            else 
              temp.push_back(nums[j++]);
        }

        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);

        for(int k = left; k <= right; k++) 
        {
            nums[k] = temp[k - left];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) 
    {
        if(left >= right){
            return;
        } 
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 1, 1, 2, 0, 0};  

    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted Array (Optimal - Merge Sort): ";

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
