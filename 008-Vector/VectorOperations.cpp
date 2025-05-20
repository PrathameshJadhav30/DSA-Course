// Vector Operations: Insert, Erase, Swap, Resize, Assign
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};

    v.insert(v.begin() + 2, 99);     // Insert 99 at index 2 (third position)
    v.erase(v.begin());               // Remove first element
    v.resize(3);                     // Resize vector to keep only first 3 elements
    vector<int> v2 = {9, 9, 9};
    v.swap(v2);                      // Swap contents of v and v2
    v.assign(5, 100);                // Assign vector with 5 elements, each = 100

    cout << "Final vector: ";
    for (int x : v){
      cout << x << " ";              // Print all elements of vector
    } 

    return 0;
}
