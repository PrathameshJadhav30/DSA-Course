#include <iostream>     // For input and output (cin, cout)
#include <string>       // For using the string datatype and functions
#include <algorithm>    // For string manipulation (though not used here explicitly)
using namespace std;

// Function to add two binary numbers represented as strings
string addBinary(string a, string b) {
    string result = "";   // To store the final binary result
    int carry = 0;        // Carry to handle overflow of binary addition

    // Make both strings equal in length by adding leading zeroes
    while (a.length() < b.length()){
       a = '0' + a;
    } 
    while (b.length() < a.length()){
       b = '0' + b;
    } 

    // Start adding from the rightmost bits (least significant bit)
    for (int i = a.length() - 1; i >= 0; i--) {
        // Convert characters to integers and add them along with carry
        int bitSum = (a[i] - '0') + (b[i] - '0') + carry;

        // Append the result of bitSum % 2 (either 0 or 1) to the left of result
        result = to_string(bitSum % 2) + result;

        // Update carry for next iteration
        carry = bitSum / 2;
    }

    // If there's a carry left after the final addition, add it to the front
    if (carry){
       result = '1' + result;
    } 

    return result; // Return the resulting binary sum
}

int main() {
    // Two binary numbers in string format
    string a = "1101"; // 13 in decimal
    string b = "1011"; // 11 in decimal

    // Perform binary addition and print the result
    cout << "Binary Addition: " << a << " + " << b << " = " << addBinary(a, b) << endl;

    return 0; 
}
