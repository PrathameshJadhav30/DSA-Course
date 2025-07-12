//Brute Force Apporach
// Problem Link: https://leetcode.com/problems/3sum/
// File: three_sum_brute.cpp

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++){
       for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);
                }
            }
       }
            
    }
        
    // Convert set to vector
    // This is necessary because the set will automatically handle duplicates        
    return vector<vector<int>>(s.begin(), s.end());
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);

    for (auto& v : res) 
    {
        for (int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
