//Problem Link: https://leetcode.com/problems/balanced-binary-tree/description/
#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to check if tree is balanced
class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

int main() {
    // Example tree
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

    Solution s;
    if (s.isBalanced(root))
        cout << "The tree is balanced " << endl;
    else
        cout << "The tree is NOT balanced " << endl;

    return 0;
}
