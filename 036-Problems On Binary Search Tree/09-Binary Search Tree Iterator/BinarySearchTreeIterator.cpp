//Problem Link: https://leetcode.com/problems/binary-search-tree-iterator/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BSTIterator class definition
class BSTIterator {
public:
    stack<TreeNode*> stk;

    // Push all left children onto the stack
    void pushLeft(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

    // Constructor
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // Return next smallest element
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
    
    // Return whether next element exists
    bool hasNext() {
        return !stk.empty();
    }
};

// Helper function to insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Main function for static testing
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Construct BST manually or via insertion
    TreeNode* root = nullptr;
    vector<int> values = {7, 3, 15, 9, 20}; // Example BST
    for (int val : values)
        root = insertBST(root, val);

    // Create BSTIterator object
    BSTIterator iterator(root);

    cout << "BST elements in sorted order using iterator:\n";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << "\n";

    return 0;
}
