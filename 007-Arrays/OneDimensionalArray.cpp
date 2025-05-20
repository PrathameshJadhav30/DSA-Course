// One-Dimensional Array and Zero Dimensional Array
#include<iostream>
using namespace std;

int main(){
    int a = 5; // Scalar variable (0-D array)
    int arr[5];  // One-Dimensional Array

    cout << "Enter 5 Elements: ";
    // Input loop for array elements
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }

    cout << "Entered Values: ";
    // Output loop to display array elements
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
