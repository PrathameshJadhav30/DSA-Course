#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;  // max-heap

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Priority Queue (max-heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // largest element first
        pq.pop();
    }
    cout << endl;

    // Min-heap version
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    cout << "Priority Queue (min-heap): ";
    while (!minpq.empty()) {
        cout << minpq.top() << " "; // smallest element first
        minpq.pop();
    }

    return 0;
}
