class Solution {
    int solve(string& s, string& t, string k, int i, int j,
              vector<vector<int>>& dp) {
        if (j == t.length()) {
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            int include = solve(s, t, k + s[i], i + 1, j + 1, dp);
            int exclude = solve(s, t, k, i + 1, j, dp);

            return dp[i][j] = include + exclude;
        }

        return dp[i][j] = solve(s, t, k, i + 1, j, dp);
    }

public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length()) {
            return 0;
        }
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, "", 0, 0, dp);
    }
};