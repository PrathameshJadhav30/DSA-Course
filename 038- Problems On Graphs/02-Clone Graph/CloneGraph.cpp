// Problem Link: https://leetcode.com/problems/clone-graph/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited; // Map original node -> cloned node

    Node* cloneGraph(Node* node) {
        // Base case: if input node is null
        if (!node)
            return nullptr;

        // If this node is already cloned, return its clone
        if (visited.find(node) != visited.end())
            return visited[node];

        // Create a new clone node with same value
        Node* cloneNode = new Node(node->val);

        // Mark this node as visited
        visited[node] = cloneNode;

        // Recursively clone all its neighbors
        for (auto neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};

// Helper function to print the graph using BFS
void printGraph(Node* node) {
    if (!node) {
        cout << "Graph is empty.\n";
        return;
    }

    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << "Node " << curr->val << " -> ";
        for (auto n : curr->neighbors) {
            cout << n->val << " ";
            if (visited.find(n) == visited.end()) {
                visited.insert(n);
                q.push(n);
            }
        }
        cout << "\n";
    }
}

int main() {
    // Constructing a simple graph manually
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:\n";
    printGraph(node1);

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    cout << "\nCloned Graph:\n";
    printGraph(clonedGraph);

    return 0;
}
