#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);                // Stores prefix product from the left
        vector<int> right(n, 1);               // Stores suffix product from the right
        vector<int> answer(n);                 // Final result array

        // Compute prefix products for each index
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];   // Product of all elements to the left of i
        }

        // Compute suffix products for each index
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1]; // Product of all elements to the right of i
        }

        // Multiply corresponding prefix and suffix products
        for (int i = 0; i < n; i++) {
            answer[i] = left[i] * right[i];        // Result is product of left and right
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};               // Input array
    vector<int> result = sol.productExceptSelf(nums);  // Call the function

    cout << "Prefix-Suffix Output: ";
    for (int val : result){
        cout << val << " ";                        // Print each value from result
    }
    cout << endl;
    return 0;
}
