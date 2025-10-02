//Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build a hashmap to store value -> index relations for inorder traversal
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildSubtree(preorder, 0, inorder.size() - 1);
    }

    TreeNode* buildSubtree(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inorderIndex = inorderMap[rootVal];

        root->left = buildSubtree(preorder, left, inorderIndex - 1);
        root->right = buildSubtree(preorder, inorderIndex + 1, right);

        return root;
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
