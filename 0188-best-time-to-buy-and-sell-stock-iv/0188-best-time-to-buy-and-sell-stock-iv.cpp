class Solution {
    int solve(int idx,bool buy,int limit,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(idx == prices.size() || limit == 0){
            return 0;
        }
        if(dp[idx][buy][limit] != -1){
            return dp[idx][buy][limit];
        }
        int ans = 0;
        if(buy == 1){
            int buykaro = -prices[idx] + solve(idx+1,0,limit,prices,dp);
            int skipkaro = solve(idx+1,1,limit,prices,dp);
            ans = max(buykaro,skipkaro);
        }
        else{
            int sellkaro = prices[idx] + solve(idx+1,1,limit-1,prices,dp);
            int skipkaro = solve(idx+1,0,limit,prices,dp);
            ans = max(sellkaro,skipkaro);
        }
        return dp[idx][buy][limit] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};