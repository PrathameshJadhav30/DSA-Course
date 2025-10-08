//Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxSum = INT_MIN; // stores the maximum path sum found so far

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // recursively get max gain from left and right subtree
        int leftGain = max(dfs(root->left), 0);   // ignore negative paths
        int rightGain = max(dfs(root->right), 0);

        // current path sum = node + left + right
        int currentPathSum = root->val + leftGain + rightGain;

        // update the global maximum path sum
        maxSum = max(maxSum, currentPathSum);

        // return max gain to parent (only one side can be continued upward)
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

// ---------- Helper code to test ----------
int main() {
    /*
            Example Tree:
                  -10
                  /  \
                 9   20
                    /  \
                   15   7
        Max Path Sum = 42 (15 + 20 + 7)
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}
