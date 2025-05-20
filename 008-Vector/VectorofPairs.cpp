// Vector of Pairs
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> vp;  // Vector to store pairs of integers

    vp.push_back({1, 2});       // Add pair (1, 2) to vector
    vp.push_back(make_pair(3, 4)); // Add pair (3, 4) to vector

    for (auto p : vp){
       cout << p.first << " " << p.second << "\n";  // Print first and second of each pair
    }
        

    return 0;
}
