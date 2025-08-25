#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.back() << endl;

    q.pop();  // removes front element

    cout << "Front after pop: " << q.front() << endl;

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
