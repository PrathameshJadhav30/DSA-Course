#include <iostream>
using namespace std;

int main() {
    int day = 3;  // Declare and initialize day

    // switch matches the value of 'day' to the correct case
    // Each case represents a possible exact value
    switch (day) {
        case 1: 
            cout << "Monday"; 
            break;  // Prevents fall-through
        case 2: 
            cout << "Tuesday"; 
            break;
        case 3: 
            cout << "Wednesday"; 
            break;
        default: 
            // Runs if no case matches
            cout << "Invalid Day";
    }

    return 0;
}
