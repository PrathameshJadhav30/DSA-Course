// Optimal Apporach - Two Pointer Approach (In-place)
//Problem Link: https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>
using namespace std;

// Class containing the function to reverse the character array
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;                  // Pointer at the beginning
        int right = s.size() - 1;      // Pointer at the end

        // Loop until both pointers meet
        while (left < right) 
        {
            swap(s[left], s[right]);   // Swap characters at left and right
            left++;                    // Move left pointer forward
            right--;                   // Move right pointer backward
        }
    }
};

int main() {
    // Declare and initialize the character vector
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;                     // Create object of Solution class
    sol.reverseString(s);            // Call function to reverse the vector

    // Print the reversed character array
    cout << "Reversed string: ";

    for (char c : s) 
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
// Output: Reversed string: o l l e h