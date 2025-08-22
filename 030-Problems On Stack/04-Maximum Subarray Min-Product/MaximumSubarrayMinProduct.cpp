//Problem Link: https://leetcode.com/problems/maximum-subarray-min-product/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        // Step 1: Prefix sums for subarray sum queries
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Find previous smaller element for each index
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        // Clear stack for next loop
        while (!st.empty()) st.pop();

        // Next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        // Step 3: Calculate max min-product
        long long maxProduct = 0;
        for (int i = 0; i < n; i++) {
            long long l = left[i] + 1;
            long long r = right[i] - 1;
            long long subarraySum = prefix[r + 1] - prefix[l];
            long long product = subarraySum * nums[i];
            maxProduct = max(maxProduct, product);
        }

        return maxProduct % MOD;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,2};
    cout << sol.maxSumMinProduct(nums1) << endl; // Output: 14

    vector<int> nums2 = {2,3,3,1,2};
    cout << sol.maxSumMinProduct(nums2) << endl; // Output: 18

    vector<int> nums3 = {3,1,5,6,4,2};
    cout << sol.maxSumMinProduct(nums3) << endl; // Output: 60

    return 0;
}
