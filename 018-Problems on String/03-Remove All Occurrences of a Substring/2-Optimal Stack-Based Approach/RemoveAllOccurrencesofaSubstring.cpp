// Optimal Approach--Using Stack
//Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/    
#include <iostream>
#include <string>
using namespace std;

// Optimal Approach using a stack-like behavior with string
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";               // Acts as a stack
        int partLen = part.length();   // Length of substring to match

        for (char c : s) 
        {
            res.push_back(c);          // Add character to the result

            // Check if the last characters match the substring 'part'
            if (res.size() >= partLen && res.substr(res.size() - partLen) == part) 
            {
                // If match found, erase the last 'part.length()' characters
                res.erase(res.end() - partLen, res.end());
            }
        }
        return res;
    }
};

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    Solution obj;
    string result = obj.removeOccurrences(s, part);

    cout << "Result after removing occurrences: " << result << endl;
    return 0;
}
// Output: Result after removing occurrences: dabcba
// Explanation: The substring "abc" is removed from the string "daabcbaabcbc" multiple times until no more occurrences are left.