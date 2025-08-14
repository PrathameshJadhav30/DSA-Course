//Optimal Apporach
//Problem link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        m[head] = newHead;

        // Step 1: Copy next pointers
        while (oldTemp != NULL) {
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Step 2: Copy random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != NULL) {
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Helper function to print the list (value + random pointer's value)
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Value: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    /*
      Example:
      Creating a list:
      1 -> 2 -> 3
      Random links: 1->3, 2->1, 3->2
    */

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    node1->random = node3;
    node2->random = node1;
    node3->random = node2;

    cout << "Original list:" << endl;
    printList(node1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(node1);

    cout << "\nCopied list:" << endl;
    printList(copiedHead);

    return 0;
}
