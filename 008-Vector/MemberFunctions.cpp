// Member Functions
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4};

    v.push_back(5);   // Add 5 at the end
    v.pop_back();     // Remove last element (5)

    cout << "Front: " << v.front() << "\n";    // First element (1)
    cout << "Back: " << v.back() << "\n";      // Last element (4)
    cout << "At(1): " << v.at(1) << "\n";      // Element at index 1 (2)
    cout << "Size: " << v.size() << "\n";      // Number of elements (4)

    // more member functions
    cout << "Capacity: " << v.capacity() << "\n"; // Total capacity allocated
    cout << "Max Size: " << v.max_size() << "\n"; // Maximum possible size

    v.reserve(10);    // Request capacity to hold at least 10 elements
    cout << "Capacity after reserve(10): " << v.capacity() << "\n";

    v.resize(6, 100); // Resize vector to 6 elements, new elements initialized to 100
    cout << "After resize to 6 with 100s: ";
    for(auto x : v){
        cout << x << " ";
    }
    cout << "\n";

    v.clear();        // Clear all elements
    cout << "Empty: " << v.empty() << "\n";  // Check if vector is empty (1 = true)

    return 0;
}
