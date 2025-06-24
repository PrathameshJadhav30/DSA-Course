//Optimal Apporach 
//Problem Link : https://leetcode.com/problems/merge-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

// Optimal: Use three pointers from the end to merge in-place
class MergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for last element in nums1's valid portion
        int j = n - 1;         // Pointer for last element in nums2
        int k = m + n - 1;     // Pointer for placing elements at the end of nums1

        // Compare elements from back and place the largest at the end
        while (i >= 0 && j >= 0) 
        {
            if (nums1[i] > nums2[j]) 
            {
                nums1[k--] = nums1[i--];
            } else 
            {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements remain in nums2, copy them
        while (j >= 0) 
        {
            nums1[k--] = nums2[j--];
        }

        // No need to copy nums1 elements; they are already in place
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    MergeSortedArray Solution;
    Solution.merge(nums1, m, nums2, n);

    cout << "Merged Array (Optimal): ";
    for (int num : nums1){
        cout << num << " ";
    } 
    cout << endl;

    return 0;
}
