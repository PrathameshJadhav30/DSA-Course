// Sorting a Vector
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = { 3, 4, 5 , 1, 2, 9, 7};

    sort(v.begin(), v.end()); // Sort vector in ascending order
    cout << "Ascending: ";
    for(int val : v){
        cout << val << " ";
    }

    sort(v.rbegin(), v.rend()); // Sort vector in descending order
    cout << "\nDescending: ";
    for(int val : v){
        cout << val << " ";
    }

    return 0;
}
