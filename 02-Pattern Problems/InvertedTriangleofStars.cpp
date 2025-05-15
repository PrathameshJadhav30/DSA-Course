// Inverted Triangle of Stars 
// Pattern: 
 
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 
#include<iostream>  // Include the input-output stream library
using namespace std;

int main() {
    int n = 5;  // Number of rows for the triangle

    // Print heading
    cout << "Inverted Triangle of Stars" << endl;

    // Outer loop for each row (starts from n and goes down to 1)
    for(int i = n; i >= 1; i--) {
        // Inner loop to print stars in each row
        for(int j = 1; j <= i; j++) {
            cout << "* ";  // Print star followed by space
        }
        cout << endl;  // Move to the next line after each row
    }

    return 0;  // Indicate successful program termination
}
