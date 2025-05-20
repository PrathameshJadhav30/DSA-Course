// Vector Tricks
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 3, 4, 4, 4, 5};

    // Remove duplicates after sorting
    sort(v.begin(), v.end());                     
    v.erase(unique(v.begin(), v.end()), v.end()); // unique shifts duplicates to end, erase removes them

    // Copy vector v to v2
    vector<int> v2 = v;

    // Search for element 3 in vector v
    if (find(v.begin(), v.end(), 3) != v.end()){
         cout << "Found 3\n";
    }
        

    // Print final vector after removing duplicates
    cout << "Final vector: ";
    for (int x : v){
      cout << x << " ";

    } 
    return 0;
}
