// multimap in STL
#include <iostream> 
#include <map>
using namespace std;

int main() {
    multimap<string, int> mmap;
    mmap.insert({"apple", 1});
    mmap.insert({"banana", 2});
    mmap.insert({"apple", 3}); // duplicate key allowed

    cout << "Multimap contents:\n";
    for (const auto& p : mmap){
        cout << p.first << " => " << p.second << endl;
    }
        
    mmap.erase("banana");

    cout << "After erasing banana:\n";
    for (const auto& p : mmap){
        cout << p.first << " => " << p.second << endl;
    }
        
    return 0;
}
