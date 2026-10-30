class Solution {
    int solve(int idx, bool buy, vector<int>&prices,vector<vector<int>>&dp) {
        if (idx == prices.size()) {
            return 0;
        }

        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }

        int profit = 0;
        if (buy == 1) {
            int buykaro = -prices[idx] + solve(idx + 1, 0, prices,dp);
            int skipkaro = 0 + solve(idx + 1, 1, prices,dp);
            profit = max(buykaro, skipkaro);
        } else {
            int sellkaro = prices[idx] + solve(idx + 1, 1, prices,dp);
            int skipkaro = 0 + solve(idx + 1, 0, prices,dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[idx][buy] = profit;
    }


    int solveTab(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){

                int profit = 0;
                if(buy){
                    int buykaro = (-prices[idx] + dp[idx+1][0]);
                    int skipkaro = ( 0 + dp[idx+1][1]);
                    profit = max(buykaro,skipkaro);
                }
                else{
                    int sellkaro = (prices[idx] + dp[idx+1][1]);
                    int skipkaro = (0 + dp[idx+1][0]);
                    profit = max(sellkaro,skipkaro);
                }

                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }


    int solveSpace(vector<int>&prices){
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){

                int profit = 0;
                if(buy){
                    int buykaro = (-prices[idx] + next[0]);
                    int skipkaro = ( 0 + next[1]);
                    profit = max(buykaro,skipkaro);
                }
                else{
                    int sellkaro = (prices[idx] + next[1]);
                    int skipkaro = (0 + next[0]);
                    profit = max(sellkaro,skipkaro);
                }

                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
public:
    int maxProfit(vector<int>& prices) { 
        // int n = prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(0, 1, prices,dp); 

        // return solveTab(prices);
        return solveSpace(prices);

    }
};