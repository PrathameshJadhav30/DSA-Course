// priority_queue in STL
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // (Min-Heap) using Custom Comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(40);
    minHeap.push(10);
    minHeap.push(30);

    cout << "Top (min): " << minHeap.top() << endl; // 10

    minHeap.pop(); // removes 10

    cout << "After pop, top: " << minHeap.top() << endl; // 30

    // (Max-Heap) Demonstration
     priority_queue<int> pq;
    pq.push(40);
    pq.push(10);
    pq.push(30);

    cout << "Top (max): " << pq.top() << endl; // 40

    pq.pop(); // removes 40

    cout << "After pop, top: " << pq.top() << endl; // 30
}
