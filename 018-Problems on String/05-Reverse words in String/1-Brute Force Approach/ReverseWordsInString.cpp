// Brute Force Approach
// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <iostream>
#include <vector>
#include <algorithm> // for reverse()
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;  // To store individual words
        int n = s.size();
        string word = "";

        // Traverse the string and extract words
        for (int i = 0; i < n; i++) 
        {
            if (s[i] != ' ') 
            {
                // Build current word character by character
                word += s[i];
            } 
            else if (!word.empty()) 
            {
                // Word completed, push to vector
                words.push_back(word);
                word = "";  // Reset for next word
            }
        }

        // Add the last word if it exists (non-empty)
        if (!word.empty()){
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Construct the final result string with single spaces
        string result = "";
        for (int i = 0; i < words.size(); i++) 
        {
            result += words[i];
            if (i < words.size() - 1){
                result += " ";  // Add space between words (not after last word)
            }
        }

        return result;
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
