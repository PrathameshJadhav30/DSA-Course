//Problem Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

    // Helper function to transfer elements from s1 to s2
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue and returns it
    int pop() {
        if (s2.empty()) {
            transfer();
        }
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Get the front element
    int peek() {
        if (s2.empty()) {
            transfer();
        }
        return s2.top();
    }

    // Returns true if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Driver code to test MyQueue
int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // 10
    cout << "Removed element: " << q.pop() << endl; // 10
    cout << "Front element after pop: " << q.peek() << endl; // 20

    q.push(40);
    cout << "Removed element: " << q.pop() << endl; // 20
    cout << "Removed element: " << q.pop() << endl; // 30
    cout << "Removed element: " << q.pop() << endl; // 40

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
