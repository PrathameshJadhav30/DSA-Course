#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Traverse the array
    for (int i = 0; i < n - 1; i++) 
    {
        int minIdx = i; // Assume the first element of the unsorted part is the minimum

        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIdx]) // If the current element is smaller than the current minimum
            {
                minIdx = j; // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13};

    selectionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr){
        cout << x << " ";
    } 

    return 0;
}
