//Problem Link: https://leetcode.com/problems/recover-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    // Main function to recover the BST
    void recoverTree(TreeNode* root) {
        helper(root);
        // Swap the values of the two wrong nodes
        if (first && second)
            swap(first->val, second->val);
    }

    // Inorder traversal to detect the two nodes
    void helper(TreeNode* node) {
        if (!node) return;

        helper(node->left);

        // Detect nodes that are out of order
        if (prev && prev->val > node->val) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;
        helper(node->right);
    }
};

// Create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Inorder traversal to print the BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Example:
               3
              / \
             1   4
                /
               2

        The correct BST should be:
               2
              / \
             1   4
                /
               3
    */

    // Create BST with swapped nodes
    TreeNode* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->right->left = newNode(2);

    cout << "Original (incorrect) BST inorder: ";
    inorder(root);
    cout << "\n";

    // Recover the BST
    Solution sol;
    sol.recoverTree(root);

    cout << "Recovered (corrected) BST inorder: ";
    inorder(root);
    cout << "\n";

    return 0;
}
