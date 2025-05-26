// vector in STL
#include <iostream>
#include <vector>
#include <algorithm> // for sort, reverse, binary_search
using namespace std;

int main() {
    vector<int> v = {3, 1, 4};

    v.push_back(5);             // Add at end
    v.pop_back();               // Remove last element
    v.insert(v.begin(), 0);     // Insert at beginning
    v[1] = 99;                  // Modify element at index 1

    cout << "Vector elements:\n";
    for (int x : v) {
        cout << x << " ";
    }

    sort(v.begin(), v.end());   // Sort ascending
    reverse(v.begin(), v.end()); // Reverse

    int x = 3;
    if (binary_search(v.begin(), v.end(), x)){
         cout << "\nFound " << x << " in vector\n";
    }
       

    auto lb = lower_bound(v.begin(), v.end(), 3);
    auto ub = upper_bound(v.begin(), v.end(), 3);
    cout << "Lower bound of 3: " << (lb - v.begin()) << endl;
    cout << "Upper bound of 3: " << (ub - v.begin()) << endl;

    v.clear(); // Empties vector
}
