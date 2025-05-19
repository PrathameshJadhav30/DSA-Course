#include <iostream>     // For input and output (cin, cout)
#include <string>       // For using string datatype and string functions
#include <algorithm>    // For string manipulation (used for erasing leading zeros)
using namespace std;

// Function to subtract binary number b from a (a - b), both represented as strings
string subtractBinary(string a, string b) {
    // Step 1: Make both binary strings of equal length by adding leading zeros
    while (a.length() < b.length()){
      a = '0' + a;
    } 
    while (b.length() < a.length()){
      b = '0' + b;
    } 

    string result = "";  // To store the final binary subtraction result
    int borrow = 0;      // Borrow flag used during subtraction

    // Step 2: Start subtracting from the rightmost bit
    for (int i = a.length() - 1; i >= 0; i--) {
        int bitA = a[i] - '0';            // Convert character to integer (0 or 1)
        int bitB = (b[i] - '0') + borrow; // Add borrow to bitB

        if (bitA < bitB) {
            // Borrow needed, so add 2 to bitA and set borrow = 1 for next step
            result = to_string(bitA + 2 - bitB) + result;
            borrow = 1;
        } else {
            // No borrow needed
            result = to_string(bitA - bitB) + result;
            borrow = 0;
        }
    }

    // Step 3: Remove leading zeros from the result
    result.erase(0, result.find_first_not_of('0'));

    // If result becomes empty after removing zeros, return "0"
    return result.empty() ? "0" : result;
}

int main() {
    string a = "1010"; // 10 in decimal
    string b = "0011"; // 3 in decimal

    // Perform binary subtraction and print the result
    cout << "Binary Subtraction: " << a << " - " << b << " = " << subtractBinary(a, b) << endl;

    return 0; // Exit the program
}
