// Array Traversal Using Function
#include<iostream>
using namespace std;

// Function to display elements of the array
void DisplayArray(int arr[], int Size){
    cout << "Array Elements:\n";
    
    // Loop through the array using the given size
    for(int i = 0; i < Size; i++)
    {
        // Print each element followed by a space
        cout << arr[i] << " ";
    }
    cout << endl; // Move to next line after printing all elements
}

int main(){
    int nums[5] = {10, 20, 30, 40, 50};  // Initialize array with 5 elements

    int size = 5;  // Store size of the array

    DisplayArray(nums, size);  // Call the function to display array

    return 0;  
}
