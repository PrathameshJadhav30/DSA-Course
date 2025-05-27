// Linear Search
#include<iostream>
using namespace std;

//Function to perform Linear Search
int linearSearch(int arr[], int n, int target){
    //Loop Through each element in array
    for(int i = 0; i < n; i++){
        //Check if the Current element is the target
        if(arr[i] == target){
            return i; //Return the index if found
        }
    }
    return -1; //Return -1 if target is not found
}

int main(){
    int arr[] = {5,10,14,24,12,45,67,89,98};
    int n = sizeof(arr)/sizeof(arr[0]); //Calculate the number of elements in the array
    int target = 89;

    int result = linearSearch(arr, n, target); //Call the linear search function

    if(result != -1){
        cout<<"Element found at index: "<<result << endl; 
    }else{
        cout<<"Element not found in the array."<<endl;
    }

    return 0;
}