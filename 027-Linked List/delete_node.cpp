#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;

    if (head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
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

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Before Deletion: ";
    display(head);

    deleteNode(head, 20);

    cout << "After Deleting 20: ";
    display(head);

    return 0;
}
