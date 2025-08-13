#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) 
            return true;

        ListNode *slow = head, *fast = head;

        // Find middle using slow & fast pointer
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half of the list
        ListNode* prev = NULL;
        while (slow != NULL) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev; // prev is now head of reversed second half
        while (right != NULL) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return NULL;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 2, 1}; // Palindrome list
    ListNode* head = createList(values);

    cout << "Linked List: ";
    printList(head);

    Solution sol;
    if (sol.isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    return 0;
}
