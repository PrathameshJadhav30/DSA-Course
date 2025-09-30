//Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;
    }
};

// Helper function to create a sample binary tree
TreeNode* buildTree() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    // Example: Find LCA of nodes 5 and 1
    TreeNode* p = root->left;   // Node 5
    TreeNode* q = root->right;  // Node 1

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " 
         << lca->val << endl;

    // Another Example: Find LCA of nodes 6 and 4
    p = root->left->left;       // Node 6
    q = root->left->right->right; // Node 4
    lca = sol.lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " 
         << lca->val << endl;

    return 0;
}
