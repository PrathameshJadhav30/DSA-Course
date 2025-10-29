//Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Codec class for serialization and deserialization of a binary tree.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:
    // Helper function for serialization
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    // Helper function for deserialization
    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Helper function to print tree in inorder traversal (for testing)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main function to test Codec
int main() {
    Codec codec;

    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    // Deserialize the string back to tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // Print inorder traversal of deserialized tree
    cout << "Inorder Traversal of Deserialized Tree: ";
    inorder(deserializedRoot);
    cout << endl;

    return 0;
}
