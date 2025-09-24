//Problem Link: https://leetcode.com/problems/subtree-of-another-tree/description/
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
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root == nullptr || subRoot == nullptr || root->val != subRoot->val) {
            return false;
        }
        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// ---------- For local testing (VS Code) ----------
int main() {
    /*
        Example tree:
            3
           / \
          4   5
         / \
        1   2

        Subtree:
          4
         / \
        1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "true" : "false") << endl;

    return 0;
}
