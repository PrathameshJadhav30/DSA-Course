#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays into one
void merge(vector<int>& arr, int l, int m, int r) {
    // Create left and right subarrays
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);  // left subarray from l to m
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);  // right subarray from m+1 to r

    int i = 0, j = 0, k = l;  // Indexes for left, right, and merged array

    // Merge the two subarrays
    while (i < left.size() && j < right.size()) 
    {
        if (left[i] <= right[j])  // Compare elements from left and right subarrays
        {
           arr[k++] = left[i++]; // Copy element from left subarray
        }   
        else  // Compare elements from right subarray
        {
           arr[k++] = right[j++]; // Copy element from right subarray
        }  
    }

    // Copy remaining elements of left subarray
    while (i < left.size()){
          arr[k++] = left[i++]; // Copy remaining elements from left subarray
    } 

    // Copy remaining elements of right subarray
    while (j < right.size()){
        arr[k++] = right[j++]; // Copy remaining elements from right subarray
        // This is necessary if the right subarray has remaining elements after the left subarray is exhausted
    } 
}

// Merge Sort function (recursive)
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) // Check if the array has more than one element
    {
        int m = l + (r - l) / 2; // Find the middle point to divide the array into two halves

        // Sort left half
        mergeSort(arr, l, m);
        // Sort right half
        mergeSort(arr, m + 1, r);
        // Merge both halves
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr){
       cout << x << " ";
    } 

    return 0;
}
// Time Complexity: O(N log N), where N is the number of elements in the array.
// Space Complexity: O(N), due to the temporary arrays used for merging.