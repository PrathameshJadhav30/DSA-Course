#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool search(Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node{val, NULL};
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 5);
    insertAtEnd(head, 15);
    insertAtEnd(head, 25);

    int key = 15;
    if (search(head, key))
        cout << key << " found in the list.\n";
    else
        cout << key << " not found in the list.\n";

    return 0;
}
