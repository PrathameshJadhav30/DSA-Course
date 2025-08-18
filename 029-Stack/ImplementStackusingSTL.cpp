#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st; // LIFO structure

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Top element
    cout << "Top element: " << st.top() << endl; // 30

    // Pop element
    st.pop();
    cout << "After pop, Top: " << st.top() << endl; // 20

    // Size
    cout << "Stack size: " << st.size() << endl;

    // Empty check
    if(st.empty()) cout << "Stack is empty\n";
    else cout << "Stack is not empty\n";

    return 0;
}
