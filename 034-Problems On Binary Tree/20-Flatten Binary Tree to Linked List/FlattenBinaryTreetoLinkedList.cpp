//Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        // Traverse right then left (reverse preorder)
        flatten(root->right);
        flatten(root->left);

        // Rearrange pointers
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// Helper function to build a binary tree from level order input
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == INT_MIN) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != INT_MIN) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        if (i < arr.size() && arr[i] != INT_MIN) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// Helper function to print flattened tree (right pointers only)
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Example: [1,2,5,3,4,null,6]
    // Represent null as INT_MIN
    vector<int> arr = {1, 2, 5, 3, 4, INT_MIN, 6};

    TreeNode* root = buildTree(arr);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened Linked List: ";
    printFlattened(root);

    return 0;
}
