#include <iostream>
using namespace std;

int main() {
    string s = "Coding";
    cout << "Indexed access: " << s[0] << endl;

    s += " is fun!";
    cout << "After append: " << s << endl;

    s[0] = 'c'; // Mutable
    cout << "After modifying first char: " << s << endl;
    return 0;
}
