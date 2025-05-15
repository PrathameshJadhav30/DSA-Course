// Pyramid Pattern 
// Pattern: 
//     *     
//    * *    
//   * * *   
//  * * * *  
// * * * * *
#include<iostream>  // Include input-output stream library
using namespace std;

int main() {
    int n = 5;  // Total number of rows in the pyramid

    // Print heading
    cout << "Pyramid Pattern" << endl;

    // Outer loop for each row (1 to n)
    for(int i = 1; i <= n; i++) {

        // Inner loop to print leading spaces for center alignment
        // Number of spaces decreases with each row
        for(int j = 1; j <= n - i; j++) {
            cout << " ";  // Print one space
        }

        // Inner loop to print stars with a space after each
        // Number of stars increases with each row
        for(int k = 1; k <= i; k++) {
            cout << "* ";  // Print star followed by a space
        }

        // Move to the next line after each row
        cout << endl;
    }

    return 0;  // End of program
}
