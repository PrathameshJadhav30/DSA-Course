// Declaration and Initialization
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a;         // Empty vector
    vector<int> b(5);      // 5 elements, default 0
    vector<int> c(5, 10);  // 5 elements, all initialized to 10
    vector<int> d = {1,2,3,4,5}; // Initialized with list

    // Print vector a (empty)
    for(auto x : a){
        cout << x << " ";
    }
    
    cout << endl;
    // Print vector b (0 0 0 0 0)
    for(auto x : b){
        cout << x << " ";
    }

    cout << endl;
    // Print vector c (10 10 10 10 10)
    for(auto x : c){
        cout << x << " ";
    }

    cout << endl;
    // Print vector d (1 2 3 4 5)
    for(auto x : d){
        cout << x << " ";
    }

    return 0;
}
