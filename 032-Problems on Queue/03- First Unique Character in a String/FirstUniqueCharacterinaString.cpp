#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);   // frequency of each character
        queue<pair<char, int>> q;  // store (character, index)

        // Step 1: count frequency & push to queue
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            q.push(make_pair(s[i], i));
        }

        // Step 2: check queue for first unique
        while (!q.empty()) {
            pair<char, int> p = q.front();
            char ch = p.first;
            int idx = p.second;

            if (freq[ch - 'a'] == 1)
                return idx;  // found first unique

            q.pop();
        }

        return -1; // no unique character
    }
};

int main() {
    Solution sol;
    string s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl; // Output: 2
    return 0;
}
