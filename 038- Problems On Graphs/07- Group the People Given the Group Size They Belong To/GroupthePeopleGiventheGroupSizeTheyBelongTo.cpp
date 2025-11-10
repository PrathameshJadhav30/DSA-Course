//Problem Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> temp_group;
        vector<vector<int>> result;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            temp_group[size].push_back(i);
            
            if (temp_group[size].size() == size) {
                result.push_back(temp_group[size]);
                temp_group[size].clear();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> groupSizes = {3,3,3,3,3,1,3};

    vector<vector<int>> ans = sol.groupThePeople(groupSizes);

    cout << "Grouped People:\n";
    for (auto &group : ans) {
        cout << "[ ";
        for (int id : group)
            cout << id << " ";
        cout << "]\n";
    }

    return 0;
}
