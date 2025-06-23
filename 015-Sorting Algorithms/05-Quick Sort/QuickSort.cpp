#include <iostream>
#include <vector>
using namespace std;

// Partition function to place pivot at correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Taking last element as pivot
    int i = low - 1;   // Index of smaller element

    // Place elements smaller than pivot to left and larger to right
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) // If current element is smaller than pivot
        {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);  // Swap current element with the smaller element
        }
    }

    // Place pivot at correct position
    swap(arr[i + 1], arr[high]);
    // Return the index of the pivot element
    // This index is now the position where the pivot is placed in the sorted array
    return i + 1;
}

// Quick Sort function (recursive)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) // Check if the array has more than one element
    {
        int pi = partition(arr, low, high);  // Partitioning index returned by partition function

        // Recursively sort left and right partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr){
       cout << x << " ";
    } 

    return 0;
}
// Time Complexity: O(N log N) on average, O(N^2) in the worst case (when the array is already sorted or reverse sorted).
// Space Complexity: O(log N) due to recursive stack space.