#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting sort based on a specific digit (exp = 1, 10, 100, ...)
void countingSortDigit(vector<int>& arr, int exp) {
    vector<int> output(arr.size());     // Output array
    vector<int> count(10, 0);           // Digits range from 0 to 9

    // Count frequency of digits
    for (int num : arr)
    {
     count[(num / exp) % 10]++; 
    }
    // Compute prefix sum (cumulative)
    for (int i = 1; i < 10; i++)
    {
       count[i] += count[i - 1];
    }  

    // Build output array (stable sort)
    for (int i = arr.size() - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to original array
    arr = output;
}

// Main Radix Sort function
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    // Apply counting sort for every digit (LSD to MSD)
    for (int exp = 1; maxVal / exp > 0; exp *= 10){
       countingSortDigit(arr, exp);
    }
        
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);

    cout << "Sorted array using Radix Sort: ";
    for (int x : arr){
      cout << x << " ";
    } 
    return 0;
}
