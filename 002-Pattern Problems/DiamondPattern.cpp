// Diamond Pattern 
// Pattern: 
//    * 
//   * * 
//  * * * 
//   * * 
//    *
#include<iostream>  // Header file for input and output
using namespace std;

int main(){
    int n = 3;  // Number of rows for the upper half of the pattern

    // Upper Part of the Diamond
    for(int i = 1; i <= n; i++){
        // Print spaces before stars
        for(int j = i; j < n; j++){
            cout << " ";  // Space for alignment
        }
        // Print stars followed by space
        for(int k = 1; k <= i; k++){
            cout << "* ";  // Star and space
        }
        cout << endl;  // Move to next line
    }

    // Lower Part of the Diamond
    for(int i = n - 1; i >= 1; i--){
        // Print spaces before stars
        for(int j = n; j > i; j--){
            cout << " ";  // Space for alignment
        }
        // Print stars followed by space
        for(int k = 1; k <= i; k++){
            cout << "* ";  // Star and space
        }
        cout << endl;  // Move to next line
    }
}
