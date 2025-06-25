#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Enter full line: ";
    getline(cin, line); // safer input
    cout << "You entered: " << line << endl;

    if (line.empty()){
        cout << "Empty string!" << endl;
        return 0;
    } else {
        cout << "Length: " << line.length() << endl;
    }
    return 0;
}
