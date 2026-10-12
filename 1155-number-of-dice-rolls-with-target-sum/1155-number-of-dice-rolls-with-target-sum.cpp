class Solution {
#define MOD 1000000007;
    int solve(int n, int k, int target, vector<vector<int>>& dp) {
        if (target < 0) {
            return 0;
        }
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) {
                ans = (ans + solve(n - 1, k, target - i, dp)) % MOD;
            }
        }
        return dp[n][target] = ans;
    }

    int solveTab(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            for (int t = 1; t <= target; t++) {
                long long ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (t - i >= 0) {
                        ans = (ans + dp[dice - 1][t - i]) % MOD;
                    }
                }
                dp[dice][t] = ans;
            }
        }

        return dp[n][target];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solve(n,k,target,dp);

        return solveTab(n, k, target);
    }
};