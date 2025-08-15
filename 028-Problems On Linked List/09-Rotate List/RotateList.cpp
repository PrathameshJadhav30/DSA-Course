//Problem Link : https://leetcode.com/problems/rotate-list/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) 
            return head;
        
        // Find length and tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // Effective rotation
        k %= length;
        if (k == 0)
            return head;
        
        // Make it circular
        tail->next = head;
        
        // Find new head
        int stepsToNewHead = length - k;
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};

// Utility function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 2;

    // Create list
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    // Rotate
    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List:  ";
    printList(head);

    return 0;
}
