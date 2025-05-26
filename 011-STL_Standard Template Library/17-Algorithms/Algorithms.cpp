// Algorithms in STL
#include <iostream>
#include <vector>
#include <algorithm> // All STL algorithms
#include <numeric>   // For accumulate
#include <iterator>  // For std::distance
using namespace std;

int main() {
    vector<int> v = {5, 3, 9, 1, 3, 5, 7, 3};

    // ---------------- Sort ----------------
    sort(v.begin(), v.end()); // Ascending
    cout << "Sorted: ";
    for (int x : v){
        cout << x << " ";
    } 
    cout << "\n";

    // ---------------- Reverse ----------------
    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";

    // ---------------- Count ----------------
    int freq = count(v.begin(), v.end(), 3);
    cout << "Count of 3: " << freq << "\n";

    // ---------------- Find ----------------
    auto it = find(v.begin(), v.end(), 9);
    if (it != v.end()) {
        cout << "Found 9 at index: " << distance(v.begin(), it) << "\n";
    }

    // Must be sorted for binary_search, lower_bound, upper_bound
    sort(v.begin(), v.end());

    // ---------------- Binary Search ----------------
    cout << "Binary Search for 5: " << binary_search(v.begin(), v.end(), 5) << "\n";

    // ---------------- Lower Bound ----------------
    auto lb = lower_bound(v.begin(), v.end(), 3);
    cout << "Lower bound of 3 at index: " << distance(v.begin(), lb) << "\n";

    // ---------------- Upper Bound ----------------
    auto ub = upper_bound(v.begin(), v.end(), 3);
    cout << "Upper bound of 3 at index: " << distance(v.begin(), ub) << "\n";

    // ---------------- Next Permutation ----------------
    vector<int> perm = {1, 2, 3};
    cout << "Next permutations:\n";
    do {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));

    // ---------------- Prev Permutation ----------------
    perm = {3, 2, 1};
    cout << "Previous permutations:\n";
    do {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "\n";
    } while (prev_permutation(perm.begin(), perm.end()));

    // ---------------- Min/Max Element ----------------
    cout << "Min element: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "Max element: " << *max_element(v.begin(), v.end()) << "\n";

    // ---------------- Accumulate ----------------
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum = " << sum << "\n";

    // ---------------- all_of / any_of / none_of ----------------
    cout << "All > 0: " << all_of(v.begin(), v.end(), [](int x){ return x > 0; }) << "\n";
    cout << "Any == 5: " << any_of(v.begin(), v.end(), [](int x){ return x == 5; }) << "\n";
    cout << "None < 0: " << none_of(v.begin(), v.end(), [](int x){ return x < 0; }) << "\n";

    // ---------------- Unique (removes consecutive duplicates) ----------------
    vector<int> uniq = {1, 1, 2, 2, 2, 3, 3, 4};
    auto it_unique = unique(uniq.begin(), uniq.end());
    uniq.erase(it_unique, uniq.end());
    cout << "Unique: ";
    for (int x : uniq) {
        cout << x << " ";
    }
    cout << "\n";

    // ---------------- Rotate ----------------
    vector<int> r = {1, 2, 3, 4, 5};
    rotate(r.begin(), r.begin() + 2, r.end()); // rotate left by 2
    cout << "Rotated (left 2): ";
    for (int x : r) {
        cout << x << " ";
    }
    cout << "\n";

    // ---------------- Partition ----------------
    vector<int> p = {1, 2, 3, 4, 5, 6};
    partition(p.begin(), p.end(), [](int x){ return x % 2 == 0; });
    cout << "Partitioned (evens first): ";
    for (int x : p) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
