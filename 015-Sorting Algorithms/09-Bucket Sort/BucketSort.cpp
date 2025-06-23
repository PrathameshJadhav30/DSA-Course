#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Main Bucket Sort function for float values between 0 and 1
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n); // Create n empty buckets

    // Distribute elements into respective buckets
    for (float val : arr) 
    {
        int index = n * val; // Index in bucket
        buckets[index].push_back(val);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++){
     sort(buckets[i].begin(), buckets[i].end());
    }
        
    // Concatenate all buckets into original array
    int idx = 0;
    for (int i = 0; i < n; i++) 
    {
        for (float val : buckets[i]) 
        {
            arr[idx++] = val;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);

    cout << "Sorted array using Bucket Sort: ";
    for (float x : arr){
       cout << x << " ";
    } 
    return 0;
}
