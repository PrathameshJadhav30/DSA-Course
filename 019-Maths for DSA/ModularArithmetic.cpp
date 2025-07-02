#include <iostream>
using namespace std;

int main() {
    int a = 1000000000, b = 1000000000, m = 1e9 + 7;

    cout << "Modular Addition: " << ((a % m) + (b % m)) % m << endl;
    cout << "Modular Subtraction: " << ((a % m) - (b % m) + m) % m << endl;
    cout << "Modular Multiplication: " << ((1LL * a % m) * (b % m)) % m << endl;

    return 0;
}
