// Recursion in Backtracking - Subset Generation
#include <iostream>
using namespace std;

void generateSubsets(string &s, int i, string curr) {
    if (i == s.length()) {
        cout << "\"" << curr << "\"" << endl;
        return;
    }
    generateSubsets(s, i + 1, curr + s[i]); // include
    generateSubsets(s, i + 1, curr);        // exclude
}

int main() {
    string s = "abc";
    cout << "Subsets of \"" << s << "\":" << endl;
    generateSubsets(s, 0, "");
    return 0;
}
