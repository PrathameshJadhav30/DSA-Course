// Number Triangle 
// Pattern: 
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4
#include<iostream>  // Include the input-output stream library
using namespace std;

int main() {
    int n = 5;  // Number of rows in the triangle

    // Print heading
    cout << "Number Triangle" << endl;

    // Outer loop to control the number of rows (from 1 to n)
    for(int i = 1; i <= n; i++) {
        // Inner loop to print numbers from 1 to i in each row
        for(int j = 1; j <= i; j++) {
            cout << j << " ";  // Print the current number followed by a space
        }
        cout << endl;  // Move to the next line after printing each row
    }

    return 0;  // Indicate successful program termination
}
