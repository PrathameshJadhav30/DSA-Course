// Operators

#include<iostream>     
using namespace std;

int main() {
    // -------------------- Arithmetic Operators --------------------
    int a = 10, b = 5; // Declare two integer variables
    cout << "Arithmetic Operators:" << endl;
    cout << "a + b = " << a + b << endl; // Addition
    cout << "a - b = " << a - b << endl; // Subtraction
    cout << "a * b = " << a * b << endl; // Multiplication
    cout << "a / b = " << a / b << endl; // Division (returns quotient)
    cout << "a % b = " << a % b << endl; // Modulus (returns remainder)

    // -------------------- Relational / Comparison Operators --------------------
    cout << "\nRelational Operators:" << endl;
    cout << "a == b: " << (a == b) << endl; // Checks if a is equal to b
    cout << "a != b: " << (a != b) << endl; // Checks if a is not equal to b
    cout << "a > b: " << (a > b) << endl;   // Checks if a is greater than b
    cout << "a < b: " << (a < b) << endl;   // Checks if a is less than b
    cout << "a >= b: " << (a >= b) << endl; // Checks if a is greater than or equal to b
    cout << "a <= b: " << (a <= b) << endl; // Checks if a is less than or equal to b

    // -------------------- Logical Operators --------------------
    cout << "\nLogical Operators:" << endl;
    cout << "a && b: " << (a && b) << endl; // Logical AND (true if both are non-zero)
    cout << "a || b: " << (a || b) << endl; // Logical OR (true if at least one is non-zero)
    cout << "!a: " << (!a) << endl;         // Logical NOT (true if a is 0)

    // -------------------- Assignment Operators --------------------
    int c = 6;
    cout << "\nAssignment Operators:" << endl;
    cout << "Initial value of c: " << c << endl;
    c += 2; // c = c + 2
    cout << "c += 2: " << c << endl;
    c -= 1; // c = c - 1
    cout << "c -= 1: " << c << endl;
    c *= 3; // c = c * 3
    cout << "c *= 3: " << c << endl;
    c %= 2; // c = c % 2
    cout << "c %= 2: " << c << endl;
    c /= 2; // c = c / 2
    cout << "c /= 2: " << c << endl;

    // -------------------- Increment and Decrement Operators --------------------
    int i = 5;
    cout << "\nIncrement/Decrement Operators:" << endl;
    cout << "Initial value of i: " << i << endl;

    cout << "Pre-increment (++i): " << ++i << endl; // Increments i first, then prints (i = 6)
    cout << "Post-increment (i++): " << i++ << endl; // Prints i (6), then increments (i = 7)
    cout << "Value of i after post-increment: " << i << endl;

    cout << "Pre-decrement (--i): " << --i << endl; // Decrements i first, then prints (i = 6)
    cout << "Post-decrement (i--): " << i-- << endl; // Prints i (6), then decrements (i = 5)
    cout << "Value of i after post-decrement: " << i << endl;

    return 0; // End of program
}
