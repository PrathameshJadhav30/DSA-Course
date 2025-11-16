//Problem Link: https://leetcode.com/problems/course-schedule-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // using the toposort in BFS method to return the order of the courses
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;

        // Build graph + indegree
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        // BFS queue initialization
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS ordering (Kahn's Algorithm)
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            cnt++;

            for(auto& nxt : adj[node]) {
                indegree[nxt]--;
                if(indegree[nxt] == 0)
                    q.push(nxt);
            }
        }

        // Detect cycles
        if(cnt < numCourses) return {};
        return result;
    }
};

int main() {
    Solution obj;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> order = obj.findOrder(numCourses, prerequisites);

    cout << "Course Order: ";
    if(order.empty()) {
        cout << "No valid order (cycle detected)" << endl;
    } else {
        for(int x : order) cout << x << " ";
        cout << endl;
    }

    return 0;
}
