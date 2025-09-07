//Problem Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
    int prevVal = -1;    // store previous node value in inorder
    int minDiff = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prevVal != -1) {
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;

        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

// -------- Helper to build tree & test ----------
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // Example BST: [4,2,6,1,3]
    TreeNode* root = nullptr;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 6);
    insertBST(root, 1);
    insertBST(root, 3);

    Solution sol;
    cout << "Minimum difference in BST = " << sol.minDiffInBST(root) << endl;

    return 0;
}
