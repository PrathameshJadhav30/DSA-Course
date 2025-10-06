//Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                index -= minIndex; // normalize to avoid overflow

                if (i == 0)
                    first = index;
                if (i == size - 1)
                    last = index;

                if (node->left)
                    q.push({node->left, 2 * index});
                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }

            int width = (int)(last - first + 1);
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
};

// Helper function to create a binary tree from vector input (level order)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    // Example input: Binary Tree [1,3,2,5,3,-1,9]
    vector<int> nodes = {1, 3, 2, 5, 3, -1, 9};

    TreeNode* root = buildTree(nodes);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "Maximum Width of Binary Tree: " << result << endl;

    return 0;
}
