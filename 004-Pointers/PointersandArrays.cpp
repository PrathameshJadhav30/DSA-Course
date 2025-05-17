//Pointers And Arrays 
#include<iostream>
using namespace std;

int main(){
    // Pointer to Array
    int arr[] = {10,20,30,40};
    int* ptr = arr;   // same as &arr[0]

    cout<<"First: "<< *ptr << endl;   //10
    cout<<"Second: "<< *(ptr + 1) << endl; //20
    cout<<"Third: "<< *(ptr + 2) << endl; // 30


    // Array of Pointers
    int a = 1, b = 2, c = 3;
    int* arr1[3] = {&a, &b, &c}; // array of pointers

    for(int i = 0; i < 3; i++){
        cout<<"Values: "<< *arr1[i] <<endl;
    }

    //Modifying Array Elements Using Pointer
    int arr2[4] = {5,10,15,20};
    int* p = arr2; //same as &arr[0]

    for(int i = 0; i < 4; i++){
        *(p + i) *= 2; // multiply each elements by 2
    }

    for(int i = 0; i < 4; i++){
        cout<< arr2[i] << " "; //Print updated array
    }
    return 0;
}