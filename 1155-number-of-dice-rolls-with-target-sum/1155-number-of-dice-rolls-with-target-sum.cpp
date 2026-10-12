class Solution {
    #define MOD 1000000007;
    int solve(int n, int k, int target,vector<vector<int>>&dp){
        if(target < 0){
            return 0;
        }
        if(n == 0){
            return target == 0 ? 1 : 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }

        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(target - i >= 0){
                ans = (ans + solve(n-1,k,target - i,dp))%MOD;
            }
        }
        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};