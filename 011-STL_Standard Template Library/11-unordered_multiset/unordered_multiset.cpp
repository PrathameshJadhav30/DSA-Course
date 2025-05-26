// unordered_multiset in STL
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<string> umset;
    umset.insert("apple");
    umset.insert("banana");
    umset.insert("apple"); // duplicate allowed

    cout << "Unordered multiset contents:\n";
    for (const auto& item : umset){
        cout << item << endl;

    }
    cout << "Count of 'apple': " << umset.count("apple") << endl; // 2
    cout << "Count of 'banana': " << umset.count("banana") << endl; // 1
    umset.erase("banana");

    cout << "After erasing banana:\n";
    for (const auto& item : umset){
        cout << item << endl;
    }
                
    return 0;
}
