// Reverse Alphabet Pyramid
// Pattern:
// E E E E E
// D D D D
// C C C
// B B
// A
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        // Print the same character multiple times
        for (int j = 0; j < n - i; j++) {
            cout << char('E' - i) << " ";
        }
        cout << endl;
    }
    return 0;
}
