// Right-Angled Triangle of Stars 
// Pattern: 
// * 
// * * 
// * * * 
// * * * * 
// * * * * *
#include<iostream>  // Header file for input and output operations
using namespace std;

int main() {
    int n = 5;  // Number of rows for the triangle

    // Print heading
    cout << "Right-Angled Triangle of Stars" << endl;

    // Outer loop for each row
    for(int i = 1; i <= n; i++) {
        // Inner loop to print stars in each row
        for(int j = 1; j <= i; j++) {
            cout << "*";  // Print star
        }
        cout << endl;  // Move to next line after each row
    }

    return 0;  // Return 0 to indicate successful execution
}
