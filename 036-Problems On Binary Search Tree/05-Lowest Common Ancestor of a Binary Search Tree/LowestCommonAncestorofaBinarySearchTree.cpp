//Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        // If both nodes are smaller than root, LCA lies in the left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // If both nodes are greater than root, LCA lies in the right subtree
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        // Otherwise, root is the LCA
        else 
            return root;
    }
};

// Helper function to insert nodes in BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Helper function to find a node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

int main() {
    // --- Static Input ---
    // BST values: [6,2,8,0,4,7,9,3,5]
    vector<int> values = {6,2,8,0,4,7,9,3,5};

    TreeNode* root = nullptr;
    for (int val : values)
        root = insertBST(root, val);

    int pVal = 2, qVal = 8; // nodes for which we find LCA
    Solution sol;

    TreeNode* p = findNode(root, pVal);
    TreeNode* q = findNode(root, qVal);

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << pVal << " and " << qVal << " is: " << lca->val << endl;

    // Another test
    pVal = 2; qVal = 4;
    p = findNode(root, pVal);
    q = findNode(root, qVal);
    lca = sol.lowestCommonAncestor(root, p, q);

    cout << "LCA of " << pVal << " and " << qVal << " is: " << lca->val << endl;

    return 0;
}
