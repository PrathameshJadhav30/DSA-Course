//Problem Link: https://leetcode.com/problems/next-greater-element-i/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Build next greater element mapping for nums2
        for (int i = 0; i < nums2.size(); i++) 
        {
            while (!st.empty() && st.top() < nums2[i]) 
            {
                nextGreater[st.top()] = nums2[i];

                st.pop();
            }
            st.push(nums2[i]);
        }

        // Remaining elements have no next greater
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1 using the map
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) 
        {
            result[i] = nextGreater[nums1[i]];
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example test
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
