//  Binary to Octal Conversion
// Binary to Octal Conversion
#include<iostream>      // For input-output functions
#include<string>        // For string manipulations
using namespace std;

// Function to convert a group of 3 binary digits to a single octal digit
char BinToOctChar(string threeBits){
    int value = 0;

    // Convert the 3-bit binary string to an integer manually (no STL)
    for (int i = 0; i < 3; i++) {
        value = value * 2 + (threeBits[i] - '0');  // Multiply previous value by 2 and add current bit
    }

    return '0' + value;  // Convert integer value to corresponding char
}

// Function to convert a binary string to octal string
string BinaryToOctal(string binary){
    // Pad binary string with leading 0s so its length becomes a multiple of 3
    while(binary.length() % 3 != 0){
        binary = '0' + binary;
    }

    string octal = "";  // This will store the resulting octal string

    // Process each group of 3 bits from left to right
    for(int i = 0; i < binary.length(); i += 3){
        string group = binary.substr(i, 3);        // Extract 3-bit group
        octal += BinToOctChar(group);              // Convert and append to result
    }

    return octal;  // Return the final octal number
}

int main(){
    string binary = "110101";  // Example binary input

    // Output the octal equivalent of the binary number
    cout << "Binary to Octal of " << binary << " = " << BinaryToOctal(binary) << endl;

    return 0;  // Exit program
}
