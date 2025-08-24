//Problem Link: https://leetcode.com/problems/min-stack/description/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;       // main stack
    stack<int> minStack; // stack to keep track of minimums

public:
    // Constructor
    MinStack() {}

    // Push element onto stack
    void push(int val) {
        st.push(val);
        // If minStack empty OR val <= current min, push onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Pop element from stack
    void pop() {
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }

    // Return top element
    int top() {
        return st.top();
    }

    // Retrieve minimum element
    int getMin() {
        return minStack.top();
    }
};
int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Current Min: " << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;            // 0
    cout << "Current Min: " << minStack.getMin() << endl; // -2

    return 0;
}
