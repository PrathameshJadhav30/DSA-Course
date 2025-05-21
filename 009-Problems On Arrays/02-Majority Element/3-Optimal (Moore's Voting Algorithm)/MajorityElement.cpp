// Optimal Approach (Moore's Voting Algorithm)
// Problem Link: https://leetcode.com/problems/majority-element/description/
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int count = 0;        // To track the count of the current candidate
    int majority = 0;     // Variable to store the potential majority element

    for(int num : nums){  // Traverse through the array
        if(count == 0){   // If count is 0, take the current number as candidate
            majority = num;
        }

        if(num == majority){  // If current number matches candidate, increase count
            count++;
        }else{                // Else decrease the count
            count--;
        }
    }
    return majority;  // Return the element which is the majority
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2,2,1,1,1};  // Input array
    cout<<"Majority Element: "<<majorityElement(nums)<<endl;  // Print result
    return 0;
}
