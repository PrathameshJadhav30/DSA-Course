// Optimal Solution - Binary Search
//Problem Link : https://www.hackerearth.com/problem/algorithm/painters-partition/
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int k, int maxSumLimit) {
    int count = 1, currSum = 0;
    // We start with one segment and a current sum of 0
    // We will iterate through the array and try to partition it into k segments
    for (int num : arr) {
        if (num > maxSumLimit){
            return false; // If a single number exceeds the limit, it's impossible to partition
        }
        // If adding the current number exceeds the limit, we need a new segment
        // So we increment the count and reset the current sum to the current number
        if (currSum + num > maxSumLimit) {
            count++;
            currSum = num; // Start a new segment with the current number
        } else {
            currSum += num; // Otherwise, we add the current number to the current segment
        }
    }
    return count <= k; // If the number of segments is less than or equal to k, return true
}

int minimizeLargestSegmentSum(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end()); // The minimum possible largest segment sum is the maximum element in the array
    if (k > arr.size()){
        return -1; // More segments than elements, not possible
    } 
    int high = accumulate(arr.begin(), arr.end(), 0); // The maximum possible largest segment sum is the sum of all elements
    int ans = high; // Initialize answer to the maximum possible sum

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if we can partition the array into k or fewer segments with max sum <= mid
        // If yes, try for a smaller maximum segment sum
        if (isPossible(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 5, 1, 2, 6};
    int k = 3; // number of segments allowed

    cout << "Minimum Maximum Segment Sum: " << minimizeLargestSegmentSum(arr, k) << endl;

    return 0;
}
// Time Complexity: O(N log S), where N is the number of elements in the array and S is the sum of all elements.
// Space Complexity: O(1), as we are using a constant amount of extra space.