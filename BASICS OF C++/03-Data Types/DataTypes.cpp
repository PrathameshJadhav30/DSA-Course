// Data Types

#include<iostream>      
using namespace std;    

int main() {
    // Declaration and initialization of variables of different data types

    int age = 20;                      // Integer data type (stores whole numbers)
    float weight = 55.4;              // Float data type (stores decimal numbers, single precision)
    double height = 5.9;              // Double data type (stores decimal numbers, double precision)
    char grade = 'A';                 // Character data type (stores a single character)
    bool isStudent = false;          // Boolean data type (true/false or 1/0)
    string name = "Prathamesh Jadhav"; // String data type (stores sequence of characters/text)

    // Output the values
    cout << "Age: " << age << endl;              // Output integer
    cout << "Age: " << age << endl;              // Repeated to show consistency
    cout << "Weight: " << weight << endl;        // Output float
    cout << "Grade: " << grade << endl;          // Output char
    cout << "Name: " << name << endl;            // Output string
    cout << "Is Student: " << isStudent << endl; // Output bool (0 = false, 1 = true)

    // Display the size of each data type using sizeof() operator
    cout << "Size of int: " << sizeof(age) << " bytes" << endl;
    cout << "Size of float: " << sizeof(weight) << " bytes" << endl;
    cout << "Size of double: " << sizeof(height) << " bytes" << endl;
    cout << "Size of char: " << sizeof(grade) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(isStudent) << " bytes" << endl;
    cout << "Size of string: " << sizeof(name) << " bytes" << endl; // Displays the size of the string object (not actual string length)

    return 0; // Indicates successful program termination
}
