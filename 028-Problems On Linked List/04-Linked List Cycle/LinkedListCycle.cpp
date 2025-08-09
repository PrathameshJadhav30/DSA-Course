//Optimal Apporach
//Problem Link:https://leetcode.com/problems/linked-list-cycle/description/
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution class
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow pointer by 1
            fast = fast->next->next;    // Move fast pointer by 2

            if (slow == fast) {         // Cycle detected
                return true;
            }
        }
        return false; // No cycle
    }
};

int main() {
    // Create nodes
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    // Link nodes: 3 -> 2 -> 0 -> -4
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create cycle: -4 -> 2
    node4->next = node2; 

    Solution solution;
    if (solution.hasCycle(node1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    // Normally we'd free memory, but since there's a cycle, we'll skip deletion here.
    return 0;
}
