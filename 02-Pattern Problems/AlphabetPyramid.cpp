//Alphabet Pyramid
//Pattern:
//     A
//    A B
//   A B C
//  A B C D
// A B C D E
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        // Print characters from 'A' onwards
        for (int k = 0; k < i; k++) {
            cout << char('A' + k) << " ";
        }
        cout << endl;
    }
    return 0;
}
