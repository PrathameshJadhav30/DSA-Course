//Problem Link: https://leetcode.com/problems/next-greater-element-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;  // store indices

        // Traverse array twice (simulate circular behavior)
        for (int i = 0; i < 2 * n; i++) 
        {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 1};
    vector<int> ans1 = sol.nextGreaterElements(nums1);
    cout << "Output: ";
    for (int x : ans1){
        cout << x << " ";
    }
    cout << endl;
    // Expected: [2, -1, 2]

    return 0;
}
