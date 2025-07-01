// Optimal Approach
// Problem Link: https://leetcode.com/problems/string-compression/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();   // Total number of characters
        int idx = 0;            // Index to write compressed characters

        for (int i = 0; i < n; i++) 
        {
            char ch = chars[i]; // Current character
            int count = 0;      // Frequency of current character

            // Count occurrences of the current character
            while (i < n && chars[i] == ch) 
            {
                count++;
                i++;
            }

            // Write the character
            chars[idx++] = ch;

            // If count > 1, write each digit of the count
            if (count > 1) 
            {
                string str = to_string(count);
                for (char digit : str) {
                    chars[idx++] = digit;
                }
            }

            i--; // Adjust index for outer loop since it will increment i
        }

        // Resize vector to new compressed length
        chars.resize(idx);

        // Return the new length of the compressed array
        return idx;
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    int len = sol.compress(chars);

    cout << "Compressed: ";
    for (int i = 0; i < len; i++) {
        if (i > 0) cout << ", "; // For better visual formatting
        cout << chars[i];
    }

    cout << "\nLength: " << len << endl;

    return 0;
}
