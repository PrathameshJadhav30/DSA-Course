// queue in STL
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("A");
    q.push("B");
    q.push("C");

    cout << "Front: " << q.front() << ", Back: " << q.back() << endl; // A, C

    q.pop(); // removes "A"

    cout << "After pop, front: " << q.front() << endl; // B
}
