//Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  // Add sentinel for easy handling

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;  // If stack empty, width = i
                } else {
                    width = i - st.top() - 1; // Else width = difference
                }
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = sol.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
