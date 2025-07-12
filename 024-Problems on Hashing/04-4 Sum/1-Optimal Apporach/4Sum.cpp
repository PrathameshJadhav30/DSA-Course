// Optimal Apporach
//Problem Link: https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) 
    {
        if (i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        for (int j = i + 1; j < n - 2; j++) 
        {
            if (j > i + 1 && nums[j] == nums[j - 1]){
                continue;
            }

            long long newTarget = (long long)target - nums[i] - nums[j];
            int left = j + 1, right = n - 1;

            // Use two pointers to find pairs that sum to newTarget
            while (left < right) 
            {
                long long sum = (long long)nums[left] + nums[right];
                if (sum == newTarget) 
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++; right--;
                    while (left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                } else if (sum < newTarget){
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);

    for (auto& v : res) 
    {
        for (int x : v){
            cout << x << " ";
        }   
        cout << endl;
    }
    return 0;
}
