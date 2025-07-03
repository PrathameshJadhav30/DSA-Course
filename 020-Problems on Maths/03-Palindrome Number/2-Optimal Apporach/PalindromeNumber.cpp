// Optimal Approach 
// Problem Link: https://leetcode.com/problems/palindrome-number/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false; // Negative numbers and multiples of 10 (except 0) are not palindromes
        } 

        int reversedHalf = 0;
        while (x > reversedHalf) 
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
};

int main() {
    Solution sol;
    int x = 121;
    cout << x << " is palindrome? " << (sol.isPalindrome(x) ? "Yes" : "No") << endl;
    return 0;
}
