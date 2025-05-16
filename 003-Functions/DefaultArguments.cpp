#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int exp = 2) {
    return pow(base, exp);
}

int main() {
    cout << power(5) << endl;     // 25 (default exponent 2)
    cout << power(2, 3) << endl;  // 8
    return 0;
}
