// Brute Force Apporach
//Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/    
#include <iostream>
#include <string>
using namespace std;

// Brute Force Approach to remove all occurrences of a substring
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continue removing until no more occurrences of 'part' are found
        while (s.length() > 0 && s.find(part) < s.length()) 
        {
            // Erase the found substring starting from its position
            s.erase(s.find(part), part.length());
        }
        return s;
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
// Explanation: The substring "abc" is removed from the string "daabcba