// array in STL
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> // for accumulate
using namespace std;

int main() {
    array<int, 5> arr = {5, 3, 2, 4, 1};

    sort(arr.begin(), arr.end()); // ascending
    reverse(arr.begin(), arr.end()); // descending

    cout << "Array elements:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\nSize: " << arr.size();
    cout << "\nFirst Element: " << arr[0];
    cout << "\nLast Element: " << arr[arr.size() - 1] << endl;
    cout << "Is array empty? " << (arr.empty() ? "Yes" : "No") << endl;
    cout << "Max Element: " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "Min Element: " << *min_element(arr.begin(), arr.end()) << endl;
    cout << "Sum of elements: " << accumulate(arr.begin(), arr.end(), 0) << endl;
    cout << "Product of elements: " << accumulate(arr.begin(), arr.end(), 1, multiplies<int>()) << endl;
    cout << "Array in reverse order:\n";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
