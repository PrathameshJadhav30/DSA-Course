#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    string s1 = "Prathamesh";
    string s2 = "Jadhav";

    // Concatenation
    string s = s1 + " " + s2;
    cout << "Concatenation: " << s << endl;

    // Substring
    cout << "Substring (0,5): " << s.substr(0, 5) << endl;

    // Search
    cout << "Found 'th': " << (s.find("th") != string::npos) << endl;

    // Replace
    s.replace(0, 5, "prath");
    cout << "After replace: " << s << endl;

    // Reverse
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;

    // Sort
    sort(s.begin(), s.end());
    cout << "Sorted chars: " << s << endl;

    // Frequency
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    cout << "Frequency of 'a': " << freq['a'] << endl;

    // Compare
    cout << "Compare 'abc' < 'abd': " << ("abc" < "abd") << endl;
    return 0;
}
