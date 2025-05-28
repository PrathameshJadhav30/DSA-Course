// Iterative Binary Search
#include<iostream>
using namespace std;

// Function for Binary Search using Iterative Approach
int binarySearch(int arr[], int n, int target){
    int start = 0;        // Start index of search space
    int end = n - 1;      // End index of search space

    // Loop while search space is valid
    while(start <= end){
        int mid = start + (end - start) / 2;  // Calculate middle index

        if(arr[mid] == target){  // Target found
            return mid;
        }
        else if(target < arr[mid]){  // Target in left half
            end = mid - 1;
        }
        else{  // Target in right half
            start = mid + 1;
        }
    }
    return -1;  // Target not found
}

int main(){
    int arr[] = {5, 10, 15, 20, 25, 30, 35};  // Sorted array
    int n = sizeof(arr)/sizeof(arr[0]);      // Number of elements
    int target = 35;                          // Element to search

    int result = binarySearch(arr, n, target);  // Call binary search
    if(result != -1){
        cout << "Element Found at index: " << result << endl;  // Print index
    }
    else{
        cout << "Element Not Found." << endl;  // Target not in array
    }

    return 0;
}
