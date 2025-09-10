//Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
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
    int maxDiameter = 0;

    int height(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // update diameter at this node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    /*
          1
         / \
        2   3
       / \
      4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;

    // Build sample tree
    TreeNode* root = buildSampleTree();

    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
