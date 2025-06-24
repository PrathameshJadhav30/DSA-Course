//Brute Force Apporach
//Problem Link : https://leetcode.com/problems/merge-sorted-array/description/
#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Brute Force: Copy nums2 into nums1 and sort the entire array
class MergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Step 1: Copy elements of nums2 to the end of nums1
        for (int i = 0; i < n; i++) 
        {
            nums1[m + i] = nums2[i];
        }

        // Step 2: Sort the full array
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    MergeSortedArray solution;
    solution.merge(nums1, m, nums2, n);

    cout << "Merged Array (Brute): ";
    for (int num : nums1){
       cout << num << " ";
    } 
    cout << endl;

    return 0;
}
// Output: Merged Array (Brute): 1 2 2 3 5 6
// Time Complexity: O((m+n)log(m+n)), where m and n are the sizes of nums1 and nums2 respectively.
// Space Complexity: O(1), since we are modifying nums1 in place.