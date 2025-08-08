//Optimal Apporach
//Problem Link : https://leetcode.com/problems/merge-two-sorted-lists/description/
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with mergeTwoLists function
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        // Case 1
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        // Case 2
        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example input lists
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    // Create the linked lists
    ListNode* head1 = createList(arr1, 3);
    ListNode* head2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    // Merge the lists
    ListNode* mergedHead = sol.mergeTwoLists(head1, head2);

    // Print the result
    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
