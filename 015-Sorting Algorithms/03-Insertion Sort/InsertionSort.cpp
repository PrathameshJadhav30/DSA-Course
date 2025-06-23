#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Traverse from the second element to the end
    for (int i = 1; i < n; i++) {
        int key = arr[i];   // Store the current element
        int j = i - 1;      // Start comparing with the previous elements

        // Shift elements of the sorted part that are greater than key
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j]; // Shift elements to the right
            j--; // Move to the previous element
        }

        // Place the key at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    insertionSort(arr);

    cout << "Sorted array: ";

    for (int x : arr){
       cout << x << " ";
    } 

    return 0;
}
