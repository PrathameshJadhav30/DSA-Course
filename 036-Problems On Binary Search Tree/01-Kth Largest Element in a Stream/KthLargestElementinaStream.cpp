//Problem Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    // Constructor
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    // Add new value and return kth largest element
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } 
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);

    cout << "Kth largest after adding 3: " << kthLargest.add(3) << endl;   // returns 4
    cout << "Kth largest after adding 5: " << kthLargest.add(5) << endl;   // returns 5
    cout << "Kth largest after adding 10: " << kthLargest.add(10) << endl; // returns 5
    cout << "Kth largest after adding 9: " << kthLargest.add(9) << endl;   // returns 8
    cout << "Kth largest after adding 4: " << kthLargest.add(4) << endl;   // returns 8

    return 0;
}
