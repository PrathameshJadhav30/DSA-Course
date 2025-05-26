// set in STL
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(2); // duplicate, will be ignored

    cout << "Set elements (automatically sorted):\n";
    for (int x : s) {
        cout << x << " "; // Output: 1 2 3
    }

    s.erase(2); // remove element 2

    auto it = s.find(3);
    if (it != s.end()) {
        cout << "\nFound 3 in the set.\n";
    } else {
        cout << "\n3 not found in the set.\n";
    }

    cout << "Set contains " << s.size() << " elements.\n";
    cout << "Is the set empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Minimum element: " << *s.begin() << endl; // 1
    cout << "Maximum element: " << *prev(s.end()) << endl; // 3
    cout << "Elements in reverse order:\n";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " "; // Output: 3 1
    }
    cout << endl;
}
