#include <iostream>
using namespace std;

int main() {
    // Outer loop (rows)
    for (int i = 1; i <= 3; i++) {
        // Inner loop (columns)
        for (int j = 1; j <= 3; j++) {
            // Prints combinations like (1,1), (1,2), etc.
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;  // Newline after each row
    }

    return 0;
}
