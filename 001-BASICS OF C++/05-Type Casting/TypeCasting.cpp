// Type Casting 

#include<iostream>
using namespace std;

int main() {
    int a = 12, b = 5;

    // -------------------- Without Type Casting (Implicit Casting) --------------------
    // Both 'a' and 'b' are integers, so integer division occurs first (12 / 5 = 2)
    // The result (2) is implicitly converted to float (2.0) and stored in result1
    float result1 = a / b;
    cout << "Without Type Casting (Implicit): " << result1 << endl;

    // -------------------- With Type Casting (Explicit Casting) --------------------
    // 'a' is explicitly cast to float before division
    // Now, float division happens: 12.0 / 5 = 2.4
    float result2 = (float)a / b;
    cout << "With Type Casting (Explicit): " << result2 << endl;

    // -------------------- Another Example: Implicit Casting --------------------
    // Implicitly converting int to float during assignment
    int x = 7;
    float y = x; // Implicit type conversion from int to float
    cout << "\nImplicit casting of int to float (y = x): " << y << endl;

    // -------------------- Another Example: Explicit Casting --------------------
    float pi = 3.14159;
    int intPi = (int)pi; // Explicit type conversion from float to int (truncates decimal)
    cout << "Explicit casting of float to int (intPi = (int)pi): " << intPi << endl;

    return 0;
}
