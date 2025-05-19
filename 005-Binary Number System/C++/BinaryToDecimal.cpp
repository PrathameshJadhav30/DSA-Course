// 1. Binary to Decimal Conversion using STL
// Binary To Decimal Conversion using STL
#include<iostream>     // For input-output operations
#include<string>       // To use string type
#include<cmath>        // To use pow() function for exponentiation

using namespace std;

// Function to convert binary string to decimal integer
int BinaryToDecimal(string binary){
    int decimal = 0;                   // To store the final decimal result
    int length = binary.length();      // Length of the binary string

    // Traverse each bit from right to left (least significant to most)
    for(int i = 0; i < length; i++){
        // If the current bit is '1', add 2^i to decimal result
        if(binary[length - 1 - i] == '1'){
            decimal += pow(2, i);
        }
    }
    return decimal;    // Return the final decimal value
}

int main(){
    string binary = "1101";   // Binary number as a string
    cout << "Binary to Decimal of " << binary << " = " << BinaryToDecimal(binary) << endl;
    return 0;
}

