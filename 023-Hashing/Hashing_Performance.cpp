#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

int main() {
    unordered_map<int, int> map;

    // Insert 1 million elements
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) 
    {
        map[i] = i * 2;
    }
    clock_t end = clock();
    cout << "Time to insert 1 million elements: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // Access
    start = clock();
    cout << "map[500000] = " << map[500000] << "\n";
    end = clock();
    cout << "Access time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}
