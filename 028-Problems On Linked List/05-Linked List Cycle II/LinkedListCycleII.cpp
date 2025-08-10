//Optimal Apporach
//Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/description/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Detect if there is a cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return NULL;
        }

        // Move slow to head, keep fast at meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // start of cycle
    }
};

// Helper function to create a linked list with a cycle
ListNode* createLinkedListWithCycle(vector<int> vals, int pos) {
    if (vals.empty()) return NULL;

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = NULL;

    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) cycleNode = curr; // store the node where cycle starts
    }

    if (pos == 0) cycleNode = head;

    if (cycleNode) {
        curr->next = cycleNode; // create cycle
    }

    return head;
}

int main() {
    Solution sol;

    // Example: 3 -> 2 -> 0 -> -4 -> cycle to node with val 2
    vector<int> vals = {3, 2, 0, -4};
    int pos = 1; // cycle starts at index 1 (value 2)
    ListNode* head = createLinkedListWithCycle(vals, pos);

    ListNode* cycleStart = sol.detectCycle(head);
    if (cycleStart) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
