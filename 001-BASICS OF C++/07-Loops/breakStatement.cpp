#include <iostream>
using namespace std;

int main() {
    // Loop from 1 to 10
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;  // Exit loop immediately when i is 5
        }
        cout << i << " ";  // Print values before break
    }

    return 0;
}
