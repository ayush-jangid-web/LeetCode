class Solution {
    int solve(int idx, int optNo, int k, vector<int>& prices, vector<vector<int>>&dp) {
        if(idx == prices.size()){
            return 0;
        }
        if(optNo == 2*k){
            return 0;
        }
        if(dp[idx][optNo] != -1){
            return dp[idx][optNo];
        }

        int profit = 0;
        if(optNo%2 == 0){
            // buy Allowed
            int buykaro = -prices[idx] + solve(idx+1,optNo+1,k,prices,dp);
            int skipkaro = 0 + solve(idx+1,optNo,k,prices,dp);
            profit = max(buykaro,skipkaro);
        }
        else{
            // sell Allowed
            int sellkaro = prices[idx] + solve(idx+1,optNo+1,k,prices,dp);
            int skipkaro = 0 + solve(idx+1,optNo,k,prices,dp);
            profit = max(sellkaro,skipkaro);
        }
        return dp[idx][optNo] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>((2*k),-1));
        return solve(0, 0, k, prices,dp);
    }
};