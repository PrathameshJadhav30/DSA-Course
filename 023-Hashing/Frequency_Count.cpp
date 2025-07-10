#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 1, 4, 2};

    unordered_map<int, int> freq;
    for (int x : arr) 
    {
        freq[x]++;
    }

    cout << "Frequency of elements:\n";
    for (auto pair : freq) 
    {
        cout << pair.first << " -> " << pair.second << "\n";
    }
    return 0;
}
