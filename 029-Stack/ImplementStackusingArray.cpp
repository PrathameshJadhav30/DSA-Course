#include <bits/stdc++.h>
using namespace std;

class Stack {
    int arr[1000];
    int topIndex;
public:
    Stack() { topIndex = -1; }

    void push(int x) {
        if(topIndex >= 999) cout << "Stack Overflow\n";
        else arr[++topIndex] = x;
    }

    void pop() {
        if(topIndex < 0) cout << "Stack Underflow\n";
        else topIndex--;
    }

    int top() {
        if(topIndex < 0) return -1;
        return arr[topIndex];
    }

    bool empty() {
        return topIndex < 0;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "After pop, Top: " << st.top() << endl;
}
