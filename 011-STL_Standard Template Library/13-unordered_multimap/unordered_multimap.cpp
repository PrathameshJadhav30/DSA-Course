// unordered_multimap in STL
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_multimap<string, int> umm;
    umm.insert({"Prathamesh ", 90});
    umm.insert({"Manoj", 85});
    umm.insert({"Sid", 95}); // duplicates allowed

    cout << "Unordered multimap contents:\n";
    for (auto& p : umm){
        cout << p.first << " => " << p.second << endl;
    }

    auto range = umm.equal_range("Prathamesh ");
    cout << "All scores for Prathamesh:\n";
    for (auto it = range.first; it != range.second; ++it){
        cout << it->first << " => " << it->second << endl;
    }
}
