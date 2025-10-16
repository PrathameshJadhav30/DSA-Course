//Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
#include <iostream>
#include <queue>
using namespace std;

/* Definition for a binary tree node */
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
    int count = 0;
    int result = 0;

    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return; // stop early if found
        
        inorder(root->left, k);
        count++;

        if (count == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};

// Helper function to insert nodes into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Function to print inorder traversal (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /* Example BST:
             5
            / \
           3   6
          / \
         2   4
        /
       1
    */

    TreeNode* root = nullptr;
    root = insertBST(root, 5);
    root = insertBST(root, 3);
    root = insertBST(root, 6);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 1);

    cout << "Inorder Traversal of BST: ";
    printInorder(root);
    cout << endl;

    Solution sol;
    int k = 3;
    int ans = sol.kthSmallest(root, k);
    cout << "The " << k << "-th smallest element in BST is: " << ans << endl;

    return 0;
}
