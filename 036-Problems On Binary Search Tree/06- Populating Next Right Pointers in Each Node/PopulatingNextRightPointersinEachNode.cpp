//Problem Link:https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        Node* leftmost = root;

        // Level by level traversal
        while (leftmost->left) {
            Node* head = leftmost;

            while (head) {
                // Connect left -> right
                head->left->next = head->right;

                // Connect right -> next left
                if (head->next)
                    head->right->next = head->next->left;

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};

// Helper: Print the tree level-wise with next pointers
void printTreeWithNext(Node* root) {
    Node* level = root;
    while (level) {
        Node* current = level;
        while (current) {
            cout << current->val << "->";
            if (current->next)
                cout << current->next->val << " ";
            else
                cout << "NULL ";
            current = current->next;
        }
        cout << endl;
        level = level->left;
    }
}

// Helper: Build a perfect binary tree for testing
Node* buildPerfectBinaryTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Build sample tree
    Node* root = buildPerfectBinaryTree();

    Solution sol;
    root = sol.connect(root);

    cout << "Level-wise next pointers after connection:\n";
    printTreeWithNext(root);

    return 0;
}
