// Brute Force Approach
// Problem Link: https://leetcode.com/problems/string-compression/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string result = "";  // To store compressed result temporarily
        int i = 0;

        while (i < chars.size()) 
        {
            char current = chars[i];  // Current character
            int count = 0;            // Count of consecutive same characters

            // Count how many times the current character repeats
            while (i < chars.size() && chars[i] == current) 
            {
                count++;
                i++;
            }

            // Append character to result
            result += current;

            // If count > 1, append the count as string
            if (count > 1) {
                result += to_string(count);  // Convert int to string
            }
        }

        // Overwrite the original vector with result characters
        for (int j = 0; j < result.size(); j++) 
        {
            chars[j] = result[j];
        }

        // Return new length of compressed array
        return result.size();
    }
};

int main() {
    Solution sol;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    
    int len = sol.compress(chars);

    cout << "Compressed: ";
    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }
    cout << "\nLength: " << len << endl;

    return 0;
}
