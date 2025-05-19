// Bitwise Operators
#include <iostream>
using namespace std;

int main() {
    cout << "Name: Prathamesh Arvind Jadhav\n";

    // 1. Bitwise Operators
    int a = 5, b = 3; // 5 = 0101, 3 = 0011 in binary
    cout << "\n[Bitwise Operators]";
    cout << "\na & b = " << (a & b) << " (AND: 0101 & 0011 = 0001)";
    cout << "\na | b = " << (a | b) << " (OR:  0101 | 0011 = 0111)";
    cout << "\na ^ b = " << (a ^ b) << " (XOR: 0101 ^ 0011 = 0110)";
    cout << "\n~a = " << (~a) << " (NOT: ~0101 = 1010 → -6 in 2's comp)";
    cout << "\na << 1 = " << (a << 1) << " (Left Shift: 0101 → 1010)";
    cout << "\na >> 1 = " << (a >> 1) << " (Right Shift: 0101 → 0010)";

    // Use case: Bit manipulation (graphics/encryption)
    return 0;
}