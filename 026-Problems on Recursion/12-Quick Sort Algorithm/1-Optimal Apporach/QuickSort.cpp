#include <iostream>
#include <vector>
using namespace std;

// Partition function: places pivot at correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap smaller element to the left
        }
    }

    // Place pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    for (int num : arr){
     cout << num << " ";
    } 
    cout << endl;

    quickSort(arr, 0, arr.size() - 1); // Apply Quick Sort

    cout << "Sorted Array: ";
    for (int num : arr){
      cout << num << " ";
    } 
    cout << endl;

    return 0;
}
