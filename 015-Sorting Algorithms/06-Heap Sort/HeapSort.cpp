#include <iostream>
#include <vector>
using namespace std;

// Heapify subtree rooted at index i in array of size n
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]){
       largest = left;
    }  

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]){
      largest = right;
    } 

    // If largest is not root, swap and continue heapifying
    if (largest != i) 
    {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--){
       heapify(arr, n, i); //
    }
        
    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(arr[0], arr[i]);      // Move current root to end
        heapify(arr, i, 0);        // Call max heapify on reduced heap
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);

    cout << "Sorted array using Heap Sort: ";
    for (int x : arr){
      cout << x << " ";
    } 
    return 0;
}
