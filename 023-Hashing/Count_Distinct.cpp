#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};

    unordered_set<int> s(arr.begin(), arr.end());
    cout << "Total distinct elements: " << s.size() << "\n";

    return 0;
}
