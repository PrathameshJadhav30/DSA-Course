// Traversing Vectors
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "Index-based: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";  // Access element by index
    }

    cout << "\nRange-based: ";
    for(auto val : v){
        cout << val << " ";   // Access each element directly
    }

    cout << "\nUsing iterator: ";
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";   // Access element using iterator
    }

    return 0;
}
