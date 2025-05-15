#include <iostream>
using namespace std;

int main() {
    // Loop from 1 to 5
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;  // Skip the rest of the loop when i is 3
        }
        cout << i << " ";  // Prints all except 3
    }

    return 0;
}
