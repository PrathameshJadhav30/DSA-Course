// Optimal Two Pointer Approach
// Problem Link: https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>
using namespace std;

// Class Solution with isPalindrome method
class Solution {
public:
    // Function to check if a given string is a valid palindrome
    bool isPalindrome(string s) {
        int left = 0; // Initialize left pointer at the beginning
        int right = s.length() - 1; // Initialize right pointer at the end

        // Loop until the two pointers meet
        while (left < right) {
            // Move left pointer if current character is not alphanumeric
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Move right pointer if current character is not alphanumeric
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters in lowercase form
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Not a palindrome if characters don't match
            }

            // Move both pointers inward
            left++;
            right--;
        }

        return true; // All characters matched, so it's a palindrome
    }
};

int main() {
    Solution sol;

    // Test case input
    string input = "A man, a plan, a canal: Panama";

    // Call function and store result
    bool result = sol.isPalindrome(input);

    // Print result
    cout << "Optimal Two Pointer Result: " << (result ? "True" : "False") << endl;

    return 0;
}
