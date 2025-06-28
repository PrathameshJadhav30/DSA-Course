//Brute Force Apporach
//Problem Link: https://leetcode.com/problems/permutation-in-string/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Brute Force approach to check if any permutation of s1 is a substring of s2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        // Sort s1 to compare with substrings
        sort(s1.begin(), s1.end());

        // Slide over s2, check each substring of length s1
        for (int i = 0; i <= n - m; i++) {
            string temp = s2.substr(i, m);  // Get substring
            sort(temp.begin(), temp.end()); // Sort it

            if (temp == s1){
               return true;    // Check if it's a permutation
            }
        }
        return false; // No permutation found
    }
};

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    Solution obj;
    bool result = obj.checkInclusion(s1, s2);

    cout << (result ? "Permutation found!" : "No permutation found.") << endl;
    return 0;
}
// Output: Permutation found!
// Explanation: The substring "ba" in "eidbaooo" is a permutation of "ab".