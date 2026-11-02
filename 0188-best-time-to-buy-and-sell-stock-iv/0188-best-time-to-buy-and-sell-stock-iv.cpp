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


    int solveTab(int k,vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>((2*k)+1,0));

        for(int idx = n-1;idx>=0;idx--){
            for(int optNo=(2*k)-1;optNo>=0;optNo--){

                int profit = 0;
                if(optNo%2 == 0){
                    // buy Allowed
                    int buykaro = -prices[idx] + dp[idx+1][optNo+1];
                    int skipkaro = 0 + dp[idx+1][optNo];
                    profit = max(buykaro,skipkaro);
                }
                else{
                    // sell Allowed
                    int sellkaro = prices[idx] + dp[idx+1][optNo+1];
                    int skipkaro = 0 + dp[idx+1][optNo];
                    profit = max(sellkaro,skipkaro);
                }
                dp[idx][optNo] = profit;
            }
        }
        return dp[0][0];
    }


    int solvespace(int k,vector<int>&prices){
        int n = prices.size();
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);

        for(int idx = n-1;idx>=0;idx--){
            for(int optNo=2*k-1;optNo>=0;optNo--){

                int ans = 0;
                if(optNo%2==0){
                    int buykaro = -prices[idx] + next[optNo+1];
                    int skipkaro = 0 + next[optNo];
                    ans = max(buykaro,skipkaro);
                }
                else{
                    int sellkaro = prices[idx] + next[optNo+1];
                    int skipkaro = 0 + next[optNo];
                    ans = max(sellkaro,skipkaro);
                }
                curr[optNo] = ans;
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>((2*k),-1));
        // return solve(0, 0, k, prices,dp);

        // return solveTab(k,prices);

        return solvespace(k,prices);
    }
};