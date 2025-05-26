// multiset in STL
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(5);
    ms.insert(3);
    ms.insert(5); // duplicates allowed

    cout << "Multiset elements:\n";
    for (int x : ms) {
        cout << x << " "; // [3, 5, 5]
    }

    ms.erase(ms.find(5)); // removes only one instance of 5

    cout << "\nAfter erasing one 5:\n";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << "\nCount of 5: " << ms.count(5) << endl; // 1
    cout << "Count of 3: " << ms.count(3) << endl; // 1
    cout << "Count of 10: " << ms.count(10) << endl; // 0
    cout << "Size of multiset: " << ms.size() << endl; // 2
    cout << "Is multiset empty? " << (ms.empty() ? "Yes" : "No") << endl; // No
    cout << "Minimum element: " << *ms.begin() << endl; // 3
    cout << "Maximum element: " << *prev(ms.end()) << endl; // 5
    cout << "Elements in reverse order:\n";
    for (auto it = ms.rbegin(); it != ms.rend(); ++it) {
        cout << *it << " "; // 5, 3
    }
    cout << endl;
}