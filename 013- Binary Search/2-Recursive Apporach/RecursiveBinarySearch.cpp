// Recursive Binary Search
#include<iostream>
using namespace std;

// Recursive Function for Binary Search
int binarySearch(int arr[], int start, int end, int target){
    if(start > end){  // Base case - target not found
        return -1;
    }

    int mid = start + (end - start) / 2;  // Calculate middle index

    if(arr[mid] == target){  // Target found at mid
        return mid;
    }
    else if(target < arr[mid]){  // Target in left half
        return binarySearch(arr, start, mid - 1, target);
    }
    else{  // Target in right half
        return binarySearch(arr, mid + 1, end, target);
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements
    int target = 50;                       // Element to search

    int result = binarySearch(arr, 0, n - 1, target);  // Call recursive search

    if(result != -1){
        cout << "Element Found at index: " << result << endl;  // Print index
    } else {
        cout << "Element Not Found." << endl;  // Target not in array
    }

    return 0;
}
