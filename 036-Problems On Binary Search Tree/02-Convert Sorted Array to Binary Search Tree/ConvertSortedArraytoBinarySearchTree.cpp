//Problem Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    // Main function to convert sorted array to BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    // Recursive function to build BST
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};

// Helper function to print inorder traversal (should give sorted order)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper function to print level order (to see structure)
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}

int main() {
    Solution solution;

    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << " Inorder Traversal (should be sorted): ";
    inorderTraversal(root);
    cout << endl << endl;

    cout << " Level Order Traversal (tree structure):" << endl;
    levelOrder(root);

    return 0;
}
