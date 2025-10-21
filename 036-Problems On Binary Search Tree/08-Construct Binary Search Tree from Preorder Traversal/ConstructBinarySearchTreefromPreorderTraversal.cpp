//Problem Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    // Helper function to recursively build the BST
    TreeNode* buildBST(vector<int>& preorder, int& index, int minVal, int maxVal) {
        if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal)
            return nullptr;

        int val = preorder[index];
        TreeNode* root = new TreeNode(val);
        index++;

        root->left = buildBST(preorder, index, minVal, val - 1);
        root->right = buildBST(preorder, index, val + 1, maxVal);

        return root;
    }

    // Main function to build BST from preorder
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MIN, INT_MAX);
    }
};

// Helper function to print inorder traversal (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
