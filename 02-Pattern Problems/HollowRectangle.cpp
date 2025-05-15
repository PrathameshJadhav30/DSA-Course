// Hollow Rectangle 
// Pattern: 
// * * * * * 
// *       * 
// *       * 
// * * * * *
#include<iostream>  // Include input-output stream library
using namespace std;

int main() {
    int rows = 4, cols = 5;  // Set the number of rows and columns

    // Print the heading
    cout << "Hollow Rectangle: " << endl;

    // Outer loop for each row
    for(int i = 1; i <= rows; i++) {
        // Inner loop for each column
        for(int j = 1; j <= cols; j++) {
            // Check if the current position is on the border
            if(i == 1 || i == rows || j == 1 || j == cols) {
                cout << "* ";  // Print star for borders
            }
            else {
                cout << "  ";  // Print space inside the rectangle
            }
        }
        cout << endl;  // Move to the next row
    }

    return 0;  // Indicate successful program termination
}

