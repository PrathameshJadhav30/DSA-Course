#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == NULL) {
            front = rear = temp;
            cout << x << " enqueued\n";
            return;
        }
        rear->next = temp;
        rear = temp;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued\n";
        front = front->next;

        if (front == NULL) rear = NULL;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    return 0;
}
