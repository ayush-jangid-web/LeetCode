class Solution {
    int solve(int idx,vector<int>&dp){
        if(idx == 0){
            return 1;
        }
        
        if(idx < 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        int ans = solve(idx-1,dp) + solve(idx-2,dp);

        return dp[idx] = ans;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};