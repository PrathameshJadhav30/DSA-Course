//Problem Link: https://leetcode.com/problems/delete-node-in-a-bst/description/
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
    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Function to delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Base case

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node found
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            TreeNode* minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};

// Helper function to insert a new node into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Helper function to print inorder traversal of BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    vector<int> values = {5, 3, 6, 2, 4, 7};

    // Create BST
    for (int val : values)
        root = insertBST(root, val);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    Solution sol;
    int key = 3;
    root = sol.deleteNode(root, key);

    cout << "Inorder after deleting " << key << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
