#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        // Store requirements as map for quick access
        unordered_map<int, int> req;
        for (auto& r : requirements) {
            req[r[0]] = r[1];
        }

        int max_inv = n * (n - 1) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(max_inv + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> prefix(max_inv + 2, 0);
            for (int j = 0; j <= max_inv; j++) {
                prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % MOD;
            }

            for (int j = 0; j <= max_inv; j++) {
                int left = max(0, j - (i - 1));
                int right = j;
                dp[i][j] = (prefix[right + 1] - prefix[left] + MOD) % MOD;
            }
        }

        int ans = 0;
        for (int inv = 0; inv <= max_inv; inv++) {
            bool ok = true;
            for (auto it = req.begin(); it != req.end(); ++it) {
                int end_idx = it->first;
                int cnt = it->second;
                if (cnt > max_inv || dp[end_idx + 1][cnt] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = (ans + dp[n][inv]) % MOD;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n1 = 3;
    vector<vector<int>> req1 = {{2, 2}, {0, 0}};
    cout << "Output 1: " << sol.numberOfPermutations(n1, req1) << endl;

    int n2 = 3;
    vector<vector<int>> req2 = {{2, 2}, {1, 1}, {0, 0}};
    cout << "Output 2: " << sol.numberOfPermutations(n2, req2) << endl;

    int n3 = 2;
    vector<vector<int>> req3 = {{0, 0}, {1, 0}};
    cout << "Output 3: " << sol.numberOfPermutations(n3, req3) << endl;

    return 0;
}
