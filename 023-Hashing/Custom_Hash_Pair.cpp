#include <iostream>
#include <unordered_map>
using namespace std;

// Custom hash function for pair<int, int>
struct hash_pair {
    size_t operator()(const pair<int, int>& p) const 
    {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

int main() {
    unordered_map<pair<int, int>, int, hash_pair> mp;

    mp[{1, 2}] = 10;
    mp[{2, 3}] = 20;

    cout << "Access pair values:\n";
    for (auto& pr : mp) 
    {
        cout << "(" << pr.first.first << "," << pr.first.second << ") => " << pr.second << "\n";
    }

    return 0;
}
