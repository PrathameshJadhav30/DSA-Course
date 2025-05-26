// unordered_set in STL
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<string> uset;
    uset.insert("apple");
    uset.insert("banana");
    uset.insert("apple"); // duplicate ignored

    cout << "Unordered set contents:\n";
    for (const auto& item : uset){
        cout << item << endl;
    }
        
    uset.erase("banana");

    cout << "After erasing banana:\n";
    for (const auto& item : uset){
        cout << item << endl;
    }
        
    return 0;
}
