// Decimal to Binary Conversion
#include<iostream>     // For input and output operations
#include<string>       // For using string datatype and string functions
using namespace std;

// Function to convert a decimal number to its binary representation
string DecimalToBinary(int decimal){
    string binary = ""; // This string will store the binary result

    // Repeat until the decimal number becomes 0
    while(decimal > 0){
        // Get remainder when divided by 2 (either 0 or 1)
        // Add the bit to the front of the binary string
        binary = to_string(decimal % 2) + binary;

        // Divide the number by 2 for the next iteration
        decimal /= 2;
    }

    // If the binary string is still empty (when input is 0), return "0"
    return binary.empty() ? "0" : binary;
}

int main(){
    int decimal = 15; // You can change this to test other numbers

    // Call the function and display the binary equivalent
    cout << "Decimal to Binary of " << decimal << " = " << DecimalToBinary(decimal) << endl;

    return 0; // Exit the program
}
