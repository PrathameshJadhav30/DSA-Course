#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                  // Get the size of the input array
        vector<int> answer(n);                // Create a result array of same size

        for (int i = 0; i < n; i++) {
            int product = 1;                  // Initialize product for each index
            for (int j = 0; j < n; j++) {
                if (i != j) {                 // Skip multiplying the current index element
                    product *= nums[j];       // Multiply all other elements
                }
            }
            answer[i] = product;              // Store the product in the result array
        }

        return answer;                        // Return the final array
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};          // Input array
    vector<int> result = sol.productExceptSelf(nums); // Get the result

    cout << "Brute Force Output: ";
    for (int val : result){
      cout << val << " ";                    // Print each element of the result
    } 
    cout << endl;
    return 0;
}
