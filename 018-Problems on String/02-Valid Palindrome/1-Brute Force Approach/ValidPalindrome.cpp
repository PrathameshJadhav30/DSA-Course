// Brute Force Approach
// Problem Link: https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>
#include <algorithm> // For reverse()
using namespace std;

// Brute Force Approach using extra space
class Solution {
public:
    // Function to check if a string is a valid palindrome
    bool isPalindrome(string s) {
        string filtered = ""; // Stores only alphanumeric characters in lowercase

        // Step 1: Filter out non-alphanumeric characters and convert to lowercase
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c); // Convert and append
            }
        }

        // Step 2: Reverse the filtered string
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());

        // Step 3: Compare the original filtered string with the reversed one
        return filtered == reversed;
    }
};

int main() {
    Solution sol;

    // Input test string
    string input = "A man, a plan, a canal: Panama";

    // Check if it is a palindrome
    bool result = sol.isPalindrome(input);

    // Output result
    cout << "Brute Force Result: " << (result ? "True" : "False") << endl;

    return 0;
}
