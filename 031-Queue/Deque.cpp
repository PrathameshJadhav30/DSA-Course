#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;

    // insert at back
    dq.push_back(10);
    dq.push_back(20);

    // insert at front
    dq.push_front(5);

    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    dq.pop_back();   // remove from back
    dq.pop_front();  // remove from front

    cout << "Deque after pops: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    return 0;
}
