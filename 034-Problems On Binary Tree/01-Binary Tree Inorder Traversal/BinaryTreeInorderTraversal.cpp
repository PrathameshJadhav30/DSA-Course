//Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
    // Recursive Inorder Traversal
    void inorderRecursive(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorderRecursive(root->left, result);
        result.push_back(root->val);
        inorderRecursive(root->right, result);
    }
}; 

TreeNode* buildSampleTree() {
    /*
           1
            \
             2
            /
           3
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    // Recursive inorder
    vector<int> recursiveResult;
    sol.inorderRecursive(root, recursiveResult);
    cout << "Recursive Inorder Traversal: ";
    
    for (int val : recursiveResult){
       cout << val << " ";
    } 
    cout << endl;

    return 0;
}
