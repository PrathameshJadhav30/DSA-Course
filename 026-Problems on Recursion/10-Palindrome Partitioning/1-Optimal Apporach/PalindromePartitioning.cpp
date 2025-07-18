//Optimal Apporach
//Problem Link :https://leetcode.com/problems/palindrome-partitioning/description/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // Recursive backtracking function to get all palindromic partitions
    void getAllParts(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if (s.empty()) {
            ans.push_back(partition);  // Base case: string fully partitioned
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);  // Get prefix

            if (isPalindrome(part)) {
                partition.push_back(part);  // Choose
                getAllParts(s.substr(i + 1), partition, ans);  // Explore
                partition.pop_back();  // Backtrack
            }
        }
    }

    // Main function to call the partitioning
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAllParts(s, partition, ans);
        return ans;
    }
};

// Main function 
int main() {
    Solution sol;
    string s;

    cout << "Enter the string: ";
    cin >> s;

    vector<vector<string>> result = sol.partition(s);

    cout << "Palindrome partitions:\n";

    for (const auto& partition : result) {
        cout << "[ ";
        for (const string& str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}

