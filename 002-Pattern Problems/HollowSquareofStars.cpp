// Hollow Square of Stars
// Pattern:
// *****
// *   *
// *   *
// *   *
// *****
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Print star on border, space inside
            if (i == 1 || i == n || j == 1 || j == n){
               cout << "*";
            }   
            else{
              cout << " ";
            }
                
        }
        cout << endl;
    }
    return 0;
}
