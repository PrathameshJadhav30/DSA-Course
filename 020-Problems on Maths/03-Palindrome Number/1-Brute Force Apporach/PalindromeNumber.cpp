// Brute Force Approach
// Problem Link: https://leetcode.com/problems/palindrome-number/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());

        return s == rev;
    }
};

int main() {
    Solution sol;
    int x = 121;
    cout << x << " is palindrome? " << (sol.isPalindrome(x) ? "Yes" : "No") << endl;
    return 0;
}
