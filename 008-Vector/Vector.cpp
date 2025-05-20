// What is Vector
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;  // Declare a vector of integers (dynamic array)

    v.push_back(10); // Add 10 to the end of vector
    v.push_back(20); // Add 20 to the end of vector
    v.push_back(30); // Add 30 to the end of vector

    // Print all elements in the vector
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";  // Access elements by index
    }

    return 0;
}
