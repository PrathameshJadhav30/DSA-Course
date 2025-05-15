// Checkerboard 
// Pattern: 
// 1 0 1 0 
// 0 1 0 1 
// 1 0 1 0
#include<iostream>  // Include the input-output stream library
using namespace std;

int main() {
    int n = 4;  // Size of the checkerboard (n x n)

    // Display title
    cout << "Checkerboard" << endl;

    // Outer loop for rows
    for(int i = 1; i <= n; i++) {
        // Inner loop for columns
        for(int j = 1; j <= n; j++) {
            // Check if the sum of current row (i) and column (j) indices is even
            // If even, print 1; else, print 0
            if((i + j) % 2 == 0) {
                cout << "1 ";  // Print 1 for even sum
            }
            else {
                cout << "0 ";  // Print 0 for odd sum
            }
        }
        cout << endl;  // Move to the next row
    }

    return 0;  // Indicate successful program termination
}
