// Problem Link: https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (visited.find(i) == visited.end()) {
                dfs(i, isConnected, visited);
            provinces++;
            }
        }
        return provinces;        
    }

private:
    void dfs(int city, vector<vector<int>>& isConnected, unordered_set<int>& visited) {
        visited.insert(city);

        for (int cur = 0; cur < isConnected[city].size(); cur++) {
            if (isConnected[city][cur] == 1 && visited.find(cur) == visited.end()) {
                dfs(cur, isConnected, visited);
            }
        }
    }
};

int main() {
   
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution obj;
    cout << obj.findCircleNum(isConnected);

    return 0;
}
