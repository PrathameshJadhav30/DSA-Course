// Insertion in Array at a Specific Index
#include<iostream>
using namespace std;

int main(){
    int arr[6] = {1, 2, 3, 4, 5}; // Array with one extra space
    int pos = 2;  // Index to insert at
    int val = 99; // Value to insert

    // Shift elements to the right from the end to the insert position
    for(int i = 5; i > pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = val; // Insert the value at the specified index

    cout << "Array After Insertion: ";
    for(int i = 0; i < 6; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
