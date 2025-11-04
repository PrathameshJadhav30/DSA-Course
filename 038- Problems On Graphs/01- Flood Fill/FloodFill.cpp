// Problem Link: https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Depth-First Search helper function
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int originalColor) {
        int n = image.size(), m = image[0].size();

        // Boundary check and color match check
        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != originalColor)
            return;

        // Recolor the current pixel
        image[r][c] = newColor;

        // Explore all 4 directions
        dfs(image, r + 1, c, newColor, originalColor);
        dfs(image, r - 1, c, newColor, originalColor);
        dfs(image, r, c + 1, newColor, originalColor);
        dfs(image, r, c - 1, newColor, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc]; 

        if (originalColor == color) // If color already same, no change
            return image;

        dfs(image, sr, sc, color, originalColor);
        return image; 
    }
};

int main() {
    Solution obj;

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    cout << "Original Image:\n";
    for (auto& row : image) {
        for (auto& pixel : row)
            cout << pixel << " ";
        cout << endl;
    }

    // Apply flood fill
    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);

    cout << "\nAfter Flood Fill (DFS) from (" << sr << ", " << sc << ") with color " << newColor << ":\n";
    for (auto& row : result) {
        for (auto& pixel : row)
            cout << pixel << " ";
        cout << endl;
    }

    return 0;
}
