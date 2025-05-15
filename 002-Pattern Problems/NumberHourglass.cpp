// Number Hourglass
// Pattern:
// 12345
//  2345
//   345
//    45
//     5
//    45
//   345
//  2345
// 12345
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    // Upper half
    for (int i = 0; i < n; i++) {
        // print spaces
        for (int j = 0; j < i; j++){
           cout << " ";
        } 
        // print numbers from i+1 to n
        for (int j = i + 1; j <= n; j++){
            cout << j;
        } 
        cout << endl;
    }
    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = i + 1; j <= n; j++){
           cout << j;
        } 
        cout << endl;
    }
    return 0;
}
