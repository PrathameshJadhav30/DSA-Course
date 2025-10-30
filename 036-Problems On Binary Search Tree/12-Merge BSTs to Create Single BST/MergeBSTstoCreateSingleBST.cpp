//Problem Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/description/
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
    void leaf(TreeNode* node, unordered_set<int>& st) {
        if (node == NULL) return;

        if (node->left == NULL && node->right == NULL) { // It's a leaf node
            st.insert(node->val);
            return;
        }

        leaf(node->left, st);
        leaf(node->right, st);
    }

    void merge(TreeNode* node, unordered_map<int, TreeNode*>& mp) {
        if (node == NULL) return;

        // If it's a leaf node and exists in the map, merge it
        if (node->left == NULL && node->right == NULL && mp.count(node->val)) {
            TreeNode* sub = mp[node->val];
            node->left = sub->left;
            node->right = sub->right;
            mp.erase(node->val);
        }

        merge(node->left, mp);
        merge(node->right, mp);
    }

    bool isbst(TreeNode* node, long low, long high) {
        if (node == NULL) return true;
        if (node->val <= low || node->val >= high) return false;

        return isbst(node->left, low, node->val) && isbst(node->right, node->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if (trees.size() == 1) return trees[0];

        unordered_set<int> leaves;
        unordered_map<int, TreeNode*> mp; // root map

        for (auto t : trees) {
            mp[t->val] = t; // add to root map
            leaf(t, leaves); // collect leaf nodes
        }

        TreeNode* root = NULL;
        for (auto t : trees) {
            if (!leaves.count(t->val)) {
                if (root) return NULL;
                root = t;
            }
        }

        if (!root) return NULL;
        mp.erase(root->val);

        merge(root, mp);

        if (!mp.empty()) return NULL;
        if (!isbst(root, LONG_MIN, LONG_MAX)) return NULL;

        return root;
    }
};

// Utility function for inorder traversal (for testing)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;

    // Example test
    // Tree1: 2 with left=1, right=3
    TreeNode* t1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    // Tree2: 1 (leaf)
    TreeNode* t2 = new TreeNode(1);

    // Tree3: 3 with right=5
    TreeNode* t3 = new TreeNode(3, nullptr, new TreeNode(5));

    vector<TreeNode*> trees = {t1, t2, t3};

    TreeNode* merged = sol.canMerge(trees);

    if (merged) {
        cout << "Merged BST (Inorder Traversal): ";
        inorder(merged);
        cout << endl;
    } else {
        cout << "Cannot merge into a valid BST." << endl;
    }

    return 0;
}
