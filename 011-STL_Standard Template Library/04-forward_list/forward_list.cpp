// forward_list in STL
#include <iostream>
#include <forward_list>
#include <iterator> // for std::prev
#include <algorithm> // for std::distance

using namespace std;

int main() {
    forward_list<int> fl = {1, 2, 3};
    fl.push_front(0);     // [0, 1, 2, 3]
    fl.pop_front();       // [1, 2, 3]

    auto it = fl.before_begin();  // before first element
    fl.insert_after(it, 99);      // [99, 1, 2, 3]

    cout << "Forward List elements:\n";
    for (int x : fl) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of forward list: " << distance(fl.begin(), fl.end()) << endl; // 4
    cout << "Is forward list empty? " << (fl.empty() ? "Yes" : "No") << endl; // No
    cout << "First element: " << fl.front() << endl; // 99
    cout << "Last element: " << *prev(fl.end()) << endl; // 3
    
}
