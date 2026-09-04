class Solution {
    int solve(vector<int>&cost,vector<int>&dp,int n){
        if(n == 0 || n == 1){
            return cost[n];
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = cost[n] + min(solve(cost,dp,n-1),solve(cost,dp,n-2));
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(solve(cost,dp,n-1),solve(cost,dp,n-2));
    }
};