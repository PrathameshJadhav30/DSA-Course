#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 2};

    unordered_set<int> s;
    bool duplicate = false;

    for (int x : arr) 
    {
        if (s.count(x)) 
        {
            duplicate = true;
            break;
        }
        s.insert(x);
    }

    if (duplicate){
        cout << "Duplicates found.\n";
    }
    else{
        cout << "No duplicates found.\n";
    }

    return 0;
}
