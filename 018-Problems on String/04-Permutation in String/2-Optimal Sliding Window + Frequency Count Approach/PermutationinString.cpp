//Optimal Approach - Sliding Window + Frequency Count
//Problem Link: https://leetcode.com/problems/permutation-in-string/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Optimal Approach using Sliding Window and Frequency Count
class Solution {
public:
    // Helper to compare two frequency arrays
    bool isFreqSame(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 26; ++i) {
            if (freq1[i] != freq2[i]){
                return false; // Frequencies do not match
            } 
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int m = s1.length(), n = s2.length();

        // If s1 is longer, no possible permutation in s2
        if (m > n){
          return false;
        } 

        vector<int> freq1(26, 0); // Frequency of s1
        vector<int> freq2(26, 0); // Frequency of current window in s2

        // Build initial frequency arrays
        for (int i = 0; i < m; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check first window
        if (isFreqSame(freq1, freq2)){
           return true;
        } 

        // Slide the window one character at a time
        for (int i = m; i < n; i++) {
            freq2[s2[i] - 'a']++;           // Add new character to window
            freq2[s2[i - m] - 'a']--;       // Remove old character from window

            if (isFreqSame(freq1, freq2)){
               return true;
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
