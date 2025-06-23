#include <iostream>
#include <vector>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    // Outer loop for number of passes
    for (int i = 0; i < n - 1; i++) {
        // Flag to check if any swapping occurred in this pass
        // If no swaps occur, the array is already sorted
        bool swapped = false;

        // Inner loop for comparisons in each pass
        for (int j = 0; j < n - i - 1; j++) 
        {
            // Swap if the element is greater than the next one
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap the elements
                // Set the flag to true indicating a swap occurred
                swapped = true;
            }
        }

        // Optimization: if no elements were swapped, the array is sorted
        if (!swapped){
            break; // No swaps means the array is already sorted, so we can exit early
        } 
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    bubbleSort(arr);

    cout << "Sorted array: ";

    for (int x : arr){
        cout << x << " ";
    } 

    return 0;
}
// Time Complexity: O(N^2), where N is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of extra space.