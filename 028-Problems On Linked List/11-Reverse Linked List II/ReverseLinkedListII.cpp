#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse a linked list between given positions
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to simplify edge cases (like reversing from head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move prev pointer to (left-1)-th node
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        // Step 2: Start reversing sublist
        ListNode* curr = prev->next;
        ListNode* next = NULL;
        ListNode* sublistPrev = NULL;

        for (int i = 0; i < right - left + 1; i++) {
            next = curr->next;
            curr->next = sublistPrev;
            sublistPrev = curr;
            curr = next;
        }

        // Step 3: Connect reversed part back to list
        prev->next->next = curr;   // Tail connects to remaining list
        prev->next = sublistPrev;  // Prev connects to new head of sublist

        return dummy->next;
    }
};

// Utility functions for testing
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    // Example 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1);
    cout << "Original List: ";
    printList(head1);
    head1 = s.reverseBetween(head1, 2, 4);
    cout << "Reversed List (2 to 4): ";
    printList(head1);

    // Example 2
    vector<int> arr2 = {5};
    ListNode* head2 = createList(arr2);
    cout << "\nOriginal List: ";
    printList(head2);
    head2 = s.reverseBetween(head2, 1, 1);
    cout << "Reversed List (1 to 1): ";
    printList(head2);

    return 0;
}
