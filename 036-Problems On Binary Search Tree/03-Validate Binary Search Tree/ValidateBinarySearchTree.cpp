//Problem Link: https://leetcode.com/problems/validate-binary-search-tree/description/
#include <iostream>
#include <climits> // For LONG_MIN and LONG_MAX
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValid(TreeNode* node, long minVal, long maxVal) {
        if (!node) {
            return true;
        }

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return isValid(node->left, minVal, node->val) &&
               isValid(node->right, node->val, maxVal);
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    /*
       Construct the following BST:
               5
              / \
             3   7
            / \   \
           2   4   8
    */
    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(8);

    Solution solution;
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
