//Optimal Apporach
//Problem Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find all paths from (0,0) to (n-1,n-1)
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size(); // Size of matrix
        vector<string> result; // To store all valid paths
        vector<vector<int>> visited(n, vector<int>(n, 0)); // Visited matrix

        // If starting or ending point is blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return result; // Return empty
        }

        string path = ""; // To build the path string
        solve(0, 0, maze, visited, path, result, n); // Start DFS from (0,0)

        sort(result.begin(), result.end()); // Lexicographical sort
        return result;
    }

private:
    // Directions: Down, Left, Right, Up
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char dir[4] = {'D', 'L', 'R', 'U'};

    // Recursive backtracking function
    void solve(int x, int y, vector<vector<int>>& maze,
               vector<vector<int>>& visited, string path,
               vector<string>& result, int n) {

        // If destination is reached, save path
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        visited[x][y] = 1; // Mark current cell as visited

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isSafe(newX, newY, maze, visited, n)) 
            {
                solve(newX, newY, maze, visited, path + dir[i], result, n);
            }
        }

        visited[x][y] = 0; // Backtrack: unmark visited
    }

    // Check if next cell is safe to visit
    bool isSafe(int x, int y, vector<vector<int>>& maze,vector<vector<int>>& visited, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
    }
};

// Driver code to test the function
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    if (paths.empty()) {
        cout << "No path exists." << endl;
    } else {
        cout << "Possible paths: " << endl;
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
