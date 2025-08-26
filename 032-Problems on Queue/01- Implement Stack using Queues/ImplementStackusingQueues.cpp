//Problem Link: https://leetcode.com/problems/implement-stack-using-queues/description
#include <bits/stdc++.h>
using namespace std;

// Stack implemented using only one Queue
class MyStack {
    queue<int> q;

public:
    MyStack() {}

    // Push element onto stack
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Move all previous elements behind the newly added element
        while (size-- > 1) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack
    int pop() {
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // Get the top element
    int top() {
        return q.front();
    }

    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // Expected 30

    cout << "Pop element: " << st.pop() << endl; // Expected 30
    cout << "Top element: " << st.top() << endl; // Expected 20

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop(); // Remove 20
    st.pop(); // Remove 10

    cout << "Is stack empty after removing all? " 
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
