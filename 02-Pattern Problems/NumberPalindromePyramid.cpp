// Number Palindrome Pyramid
//Pattern:
//     1
//    121
//   12321
//  1234321
// 123454321
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Print spaces before the numbers
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        // Print ascending numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        // Print descending numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
