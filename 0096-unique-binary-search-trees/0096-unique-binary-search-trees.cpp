class Solution {
    // recursion TLE
    int solve(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solve(i-1) * solve(n-i);
        }
        return ans;
    }

    int solveMemo(int n,vector<int>&dp){
        if(n == 0 || n== 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            ans += solveMemo(i-1,dp)* solveMemo(n-i,dp);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        // return solve(n);

        vector<int>dp(n+1,-1);
        return solveMemo(n,dp);
    }
};