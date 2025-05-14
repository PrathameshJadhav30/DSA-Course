#include <iostream>
using namespace std;

int main() {
    int i = 1;

    // do-while loop executes the body at least once
    // Condition is checked after execution
    do {
        cout << i << " ";  // Print value
        i++;  // Increment i
    } while (i <= 5);  // Condition checked after loop body

    return 0;
}
