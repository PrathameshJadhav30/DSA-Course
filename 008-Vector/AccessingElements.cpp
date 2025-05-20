// Accessing Elements
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v = {5, 10, 15};

    cout << v[1] << "\n";      // Fast access to 2nd element (10)
    cout << v.at(2) << "\n";   // Safe access to 3rd element (15), with bounds checking

    return 0;
}
