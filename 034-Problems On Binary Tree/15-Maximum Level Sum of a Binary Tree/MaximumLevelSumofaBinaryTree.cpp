//Problem Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;                // current level
        int maxLevel = 1;             // level with maximum sum
        long long maxSum = root->val; // store max sum

        while (!q.empty()) {
            int size = q.size();
            long long currSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                currSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};

// Helper function to build the example tree [1,7,0,7,-8,null,null]
TreeNode* buildExampleTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    return root;
}

// Helper function to build second example [989,null,10250,98693,-89388,null,null,null,-32127]
TreeNode* buildExampleTree2() {
    TreeNode* root = new TreeNode(989);
    root->right = new TreeNode(10250);
    root->right->left = new TreeNode(98693);
    root->right->right = new TreeNode(-89388);
    root->right->right->right = new TreeNode(-32127);
    return root;
}

int main() {
    Solution sol;

    // Example 1
    TreeNode* root1 = buildExampleTree1();
    cout << "Example 1 Output: " << sol.maxLevelSum(root1) << endl;

    // Example 2
    TreeNode* root2 = buildExampleTree2();
    cout << "Example 2 Output: " << sol.maxLevelSum(root2) << endl;

    return 0;
}
