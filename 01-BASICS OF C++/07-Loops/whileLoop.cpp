#include <iostream>
using namespace std;

int main() {
    int i = 1;  // Initialization

    // while loop checks the condition before running
    // Good when number of iterations is unknown
    while (i <= 5) {
        cout << i << " ";  // Print current value
        i++;  // Increment after printing
    }

    return 0;
}
