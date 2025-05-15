// Floyd’s Triangle 
// Pattern: 
// 1 
// 2 3 
// 4 5 6 
// 7 8 9 10
#include<iostream>  // Include the input-output stream library
using namespace std;

int main() {
    int n = 4;         // Number of rows for Floyd's Triangle
    int num = 1;       // Starting number to be printed

    // Display heading
    cout << "Floyd's Triangle" << endl;

    // Outer loop for each row
    for(int i = 1; i <= n; i++) {
        // Inner loop for printing numbers in each row
        for(int j = 1; j <= i; j++) {
            cout << num << " ";  // Print the current number
            num++;               // Increment number for next print
        }
        cout << endl;  // Move to the next line after each row
    }

    return 0;  // Indicate successful program termination
}
