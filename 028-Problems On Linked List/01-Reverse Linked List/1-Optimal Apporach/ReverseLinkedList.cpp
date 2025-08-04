//Optimal Apporach
//Problem Link: https://leetcode.com/problems/reverse-linked-list/description/
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Class containing the reverseList method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;     // Save next node
            curr->next = prev;     // Reverse current node pointer
            prev = curr;           // Move prev forward
            curr = next;           // Move curr forward
        }

        return prev; // New head
    }
};

// Utility function to insert node at the end
void insertNode(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    ListNode* head = nullptr;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original List:\n";
    printList(head);

    // Reverse the list
    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "\nReversed List:\n";
    printList(reversedHead);

    return 0;
}
