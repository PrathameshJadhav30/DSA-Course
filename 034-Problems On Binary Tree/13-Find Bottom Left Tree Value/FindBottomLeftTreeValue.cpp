//Problem Link: https://leetcode.com/problems/find-bottom-left-tree-value/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;

        while (!q.empty()) {
            int size = q.size();
            ans = q.front()->val;  // first node of each level is leftmost

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1: root = [2,1,3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    cout << "Output (Example 1): " << sol.findBottomLeftValue(root1) << endl;

    // Example 2: root = [1,2,3,4,null,5,6,null,null,7]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(6);
    root2->right->left->left = new TreeNode(7);

    cout << "Output (Example 2): " << sol.findBottomLeftValue(root2) << endl;

    return 0;
}
