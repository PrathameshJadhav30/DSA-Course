#include <bits/stdc++.h>
using namespace std;

// Node structure for BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BST Class
class BST {
public:
    Node* root;

    BST() { root = nullptr; }

    // Insert a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    // Search for a value
    bool search(Node* node, int key) {
        if (node == nullptr)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Find minimum node (used for deletion)
    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Delete a node
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else {
            // Node found: 3 possible cases
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Two children: find inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Traversals
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    // Insert elements
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "Inorder Traversal: ";
    tree.inorder(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    tree.preorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    tree.postorder(root);
    cout << "\n";

    // Search example
    int key = 40;
    cout << "\nSearching for " << key << ": ";
    cout << (tree.search(root, key) ? "Found" : "Not Found") << "\n";

    // Delete example
    cout << "\nDeleting 30...\n";
    root = tree.deleteNode(root, 30);
    cout << "Inorder after deletion: ";
    tree.inorder(root);
    cout << "\n";

    return 0;
}
