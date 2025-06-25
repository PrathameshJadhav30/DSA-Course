#include <iostream>
using namespace std;

int main() {
    string s = "abc";
    s += "d"; // O(1) amortized append
    cout << "Access s[2]: " << s[2] << endl; // O(1)
    cout << "Full string: " << s << endl;
    return 0;
}
