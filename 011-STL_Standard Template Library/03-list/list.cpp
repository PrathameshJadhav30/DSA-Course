// list in STL
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lst = {1, 2, 3};
    lst.push_front(0);  // [0, 1, 2, 3]
    lst.push_back(4);   // [0, 1, 2, 3, 4]

    auto it = lst.begin();
    advance(it, 2);     // Move to index 2
    lst.insert(it, 99); // [0, 1, 99, 2, 3, 4]

    cout << "List elements:\n";
    for (int x : lst) {
        cout << x << " "; // Output: 0 1 99 2 3 4
    }
    cout << endl;
    cout << "Size of list: " << lst.size() << endl; // 6
    cout << "Is list empty? " << (lst.empty() ? "Yes" : "No") << endl; // No
    cout << "First element: " << lst.front() << endl; // 0
    cout << "Last element: " << lst.back() << endl; // 4
}
