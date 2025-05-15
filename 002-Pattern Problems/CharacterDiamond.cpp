// Character Diamond
// Pattern:
//    A
//   ABA
//  ABCBA
// ABCDCBA
//  ABCBA
//   ABA
//    A
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    // Upper half
    for (int i = 1; i <= n; i++) {
        // spaces
        for (int j = i; j < n; j++){
           cout << " ";
        } 
        // increasing characters
        for (int j = 0; j < i; j++){
          cout << char('A' + j);
        } 
        // decreasing characters
        for (int j = i - 2; j >= 0; j--){
          cout << char('A' + j);
        } 
        cout << endl;
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--){
           cout << " ";
        } 
        for (int j = 0; j < i; j++){
           cout << char('A' + j);
        } 
        for (int j = i - 2; j >= 0; j--){
           cout << char('A' + j);
        } 
        cout << endl;
    }
    return 0;
}

