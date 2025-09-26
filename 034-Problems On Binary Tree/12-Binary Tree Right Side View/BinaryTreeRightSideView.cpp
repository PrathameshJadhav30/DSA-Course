//Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/description/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // if it's the last node of this level, add to result
                if (i == size - 1) result.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};

// Helper function to build a tree from vector 
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;

    // Example 1: root = [1,2,3,null,5,null,4]
    vector<string> nodes1 = {"1","2","3","null","5","null","4"};
    TreeNode* root1 = buildTree(nodes1);
    vector<int> ans1 = sol.rightSideView(root1);
    cout << "Output 1: ";
    for (int val : ans1) cout << val << " ";
    cout << endl;

    // Example 2: root = [1,2,3,4,null,null,null,5]
    vector<string> nodes2 = {"1","2","3","4","null","null","null","5"};
    TreeNode* root2 = buildTree(nodes2);
    vector<int> ans2 = sol.rightSideView(root2);
    cout << "Output 2: ";
    for (int val : ans2) cout << val << " ";
    cout << endl;

    // Example 3: root = [1,null,3]
    vector<string> nodes3 = {"1","null","3"};
    TreeNode* root3 = buildTree(nodes3);
    vector<int> ans3 = sol.rightSideView(root3);
    cout << "Output 3: ";
    for (int val : ans3) cout << val << " ";
    cout << endl;

    // Example 4: root = []
    vector<string> nodes4 = {};
    TreeNode* root4 = buildTree(nodes4);
    vector<int> ans4 = sol.rightSideView(root4);
    cout << "Output 4: ";
    for (int val : ans4) cout << val << " ";
    cout << endl;

    return 0;
}
