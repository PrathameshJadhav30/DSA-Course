//Problem Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }

    void reverseInorder(TreeNode* node) {
        if (!node) return;

        reverseInorder(node->right);

        sum += node->val;
        node->val = sum;

        reverseInorder(node->left);
    }
};

// ========== Helper functions to build and print tree ==========

// Print tree in level-order for easy checking
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Build tree from vector with null as INT_MIN
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != INT_MIN) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    Solution sol;

    // Example 1:
    vector<int> nodes = {4,1,6,0,2,5,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8};
    TreeNode* root = buildTree(nodes);

    cout << "Original BST (level order):" << endl;
    printLevelOrder(root);

    TreeNode* gstRoot = sol.bstToGst(root);

    cout << "Greater Sum Tree (level order):" << endl;
    printLevelOrder(gstRoot);

    return 0;
}
