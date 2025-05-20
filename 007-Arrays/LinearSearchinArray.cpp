// Linear Search in Array
#include<iostream>
using namespace std;

int main(){
    int arr[5] = {10, 20, 30, 40, 50}; // Array elements
    int key = 30; // Element to search for
    bool found = false; // Flag to track if key is found

    // Traverse the array
    for(int i = 0; i < 5; i++){
        if(arr[i] == key){ // Check for match
            cout << "Element found at index " << i << endl;
            found = true;
            break; // Exit loop once found
        }
    }

    if(!found){
        cout << "Element not Found." << endl;
    }

    return 0;
}
