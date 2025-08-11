//optimal Approach
//Problem Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    // Helper function to flatten from a given node
    Node* flattenDFS(Node* prev, Node* curr) {
        if (!curr) return prev; // End of branch

        curr->prev = prev;
        prev->next = curr;

        Node* nextNode = curr->next; // Save next pointer

        // Flatten the child list first
        Node* tail = flattenDFS(curr, curr->child);
        curr->child = NULL; // Remove child pointer after flattening

        // Flatten the saved next pointer list
        return flattenDFS(tail, nextNode);
    }

    Node* flatten(Node* head) {
        if (!head) return head;

        Node dummy(0);
        flattenDFS(&dummy, head);
        dummy.next->prev = NULL; // Head's prev should be null
        return dummy.next;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    /*
        Example: 
        1 - 2 - 3 - 4 - 5 - 6
                |
                7 - 8 - 9 - 10
                    |
                    11 - 12
    */
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // First level
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Second level
    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    // Third level
    n8->child = n11;
    n11->next = n12; n12->prev = n11;

    Solution sol;
    Node* head = sol.flatten(n1);
    printList(head); // Expected: 1 2 3 7 8 11 12 9 10 4 5 6
    return 0;
}
