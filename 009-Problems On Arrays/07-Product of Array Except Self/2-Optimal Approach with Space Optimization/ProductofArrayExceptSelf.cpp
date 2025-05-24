#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);              // Initialize result array with 1s

        // Step 1: Store prefix product from the left
        for (int i = 1; i < n; i++) {
            answer[i] = answer[i - 1] * nums[i - 1];  // Product of all elements to the left of i
        }

        int right = 1;                         // Initialize right suffix product

        // Step 2: Multiply result with suffix product from the right
        for (int i = n - 1; i >= 0; i--) {
            answer[i] = answer[i] * right;     // Multiply with the right product
            right *= nums[i];                  // Update right product
        }

        return answer;                         // Final result array
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};           // Input array
    vector<int> result = sol.productExceptSelf(nums);  // Call the function

    cout << "Optimized Output: ";
    for (int val : result){
        cout << val << " ";                   // Print each element in result
    }
    cout << endl;
    return 0;
}
