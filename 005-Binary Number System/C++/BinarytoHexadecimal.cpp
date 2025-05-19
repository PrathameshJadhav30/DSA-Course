// Binary to Hexadecimal Conversion
#include<iostream>      // For input-output functions
#include<string>        // For string manipulations
#include<algorithm>     // For using algorithms like padding, if needed
using namespace std;

// Function to convert a group of 4 binary digits to a hexadecimal character
char BinToHexChar(string fourBits){
    // Convert the 4-bit binary string to decimal integer using base 2
    int value = stoi(fourBits, nullptr, 2);

    // If value is 0-9, return corresponding char '0' to '9'
    if(value < 10){
        return '0' + value;
    }

    // If value is 10-15, return corresponding char 'A' to 'F'
    return 'A' + (value - 10);
}

// Function to convert a binary string to its hexadecimal representation
string BinaryToHex(string binary){
    // Pad binary string with leading 0s to make its length a multiple of 4
    while(binary.length() % 4 != 0){
        binary = '0' + binary;
    }

    string hex = ""; // This will hold the final hexadecimal result

    // Process each group of 4 bits from left to right
    for(int i = 0; i < binary.length(); i += 4){
        // Extract a group of 4 bits and convert to hex
        hex += BinToHexChar(binary.substr(i, 4));
    }

    return hex; // Return the final hexadecimal string
}

int main(){
    string binary = "11010110"; // You can change this to test other binary values

    // Output the hexadecimal equivalent of the binary number
    cout << "Binary to Hexadecimal of " << binary << " = " << BinaryToHex(binary) << endl;

    return 0; // Exit program
}
