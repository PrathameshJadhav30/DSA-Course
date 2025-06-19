// Optimal Approach - Binary Search
// Problem Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/
// 📚 Allocate Minimum Pages to Students - 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Check if allocation with maxPages is possible
    bool isPossible(vector<int>& arr, int k, int maxPages) {
        int students = 1;
        int pagesSum = 0;

        for (int i = 0; i < arr.size(); i++) 
        {
            if (arr[i] > maxPages){
                return false; // If a single book has more pages than maxPages, allocation is impossible
            } 

            if (pagesSum + arr[i] > maxPages) {
                students++;
                pagesSum = arr[i];
            } else {
                pagesSum += arr[i];
            }
        }
        return students <= k;
    }

    // Binary Search on answer
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n){
            return -1; // More students than books, not possible
        } 

        int low = *max_element(arr.begin(), arr.end());
        int high = 0;
        for (int i = 0; i < n; i++){
            high += arr[i];
        } 

        int result = -1;

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) 
            {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    cout << "Minimum pages allocated: " << obj.findPages(books, students) << endl; // Output: 113

    return 0;
}
// Time Complexity: O(n log(sum of pages))
// Space Complexity: O(1)