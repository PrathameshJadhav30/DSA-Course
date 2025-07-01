// Optimal Approach
// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <iostream>
#include <algorithm> // for reverse()
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) 
        {
            string word = "";

            // Step 2: Skip any extra spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            // Step 3: Extract a word (non-space sequence)
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }

            // Step 4: Reverse the individual word back to correct form
            reverse(word.begin(), word.end());

            // Step 5: Append to the result with one space
            if (!word.empty()) {
                ans += " " + word;
            }
        }

        // Step 6: Remove the leading space (if any)
        return ans.substr(1);  // as first word was added with leading space
    }
};

int main() {
    Solution sol;
    string input = "  Hello   world! This is   C++  ";
    cout << "Input: \"" << input << "\"" << endl;

    string output = sol.reverseWords(input);
    cout << "Output: \"" << output << "\"" << endl;

    return 0;
}
