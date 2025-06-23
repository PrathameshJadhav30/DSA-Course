#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort (non-negative integers only)
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end()); // Find maximum value
    vector<int> count(maxVal + 1, 0);                   // Frequency array

    // Count frequency of each element
    for (int num : arr){
       count[num]++;
    }
        

    // Reconstruct the array in sorted order
    int index = 0;
    for (int i = 0; i <= maxVal; i++) 
    {
        while (count[i]--) 
        {
            arr[index++] = i;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    cout << "Sorted array using Counting Sort: ";
    for (int x : arr){
       cout << x << " ";
    } 
    return 0;
}
