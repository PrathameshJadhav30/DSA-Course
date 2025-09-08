//Problem Link: https://leetcode.com/problems/same-tree/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null -> same
        if (!p && !q) return true;

        // If one is null and the other is not -> different
        if (!p || !q) return false;

        // Check values and recurse for left and right subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

// --------- Helper functions for testing ----------
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    Solution sol;

    // Example 1
    TreeNode* p = newNode(1);
    p->left = newNode(2);
    p->right = newNode(3);

    TreeNode* q = newNode(1);
    q->left = newNode(2);
    q->right = newNode(3);

    cout << (sol.isSameTree(p, q) ? "True" : "False") << endl; // Output: True

    // Example 2
    TreeNode* p2 = newNode(1);
    p2->left = newNode(2);

    TreeNode* q2 = newNode(1);
    q2->right = newNode(2);

    cout << (sol.isSameTree(p2, q2) ? "True" : "False") << endl; // Output: False

    return 0;
}
