#include <iostream>
using namespace std;

int main() {
    // for loop is best when number of iterations is known
    // Syntax: for (start; condition; increment)
    for (int i = 1; i <= 5; i++) {
        // Loop runs from i=1 to i=5, incrementing by 1
        cout << i << " ";  // Print current value of i
    }

    return 0;
}
