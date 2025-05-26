// deque in STL
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(1);   // [1]
    dq.push_front(2);  // [2, 1]
    dq.push_back(3);   // [2, 1, 3]
    dq.pop_front();    // [1, 3]
    dq.pop_back();     // [1]

    cout << "Deque elements:\n";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of deque: " << dq.size() << endl; // 1
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl; // No
    cout << "First element: " << dq.front() << endl; // 1
    cout << "Last element: " << dq.back() << endl; // 1
    
}
