class Solution {
    int solve(int idx, bool buy, int limit, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (idx == prices.size()) {
            return 0;
        }
        if (limit == 0) {
            return 0;
        }
        if (dp[idx][buy][limit] != -1) {
            return dp[idx][buy][limit];
        }
        int ans = 0;
        if (buy == 1) {
            int buykaro = -prices[idx] + solve(idx + 1, 0, limit, prices, dp);
            int skipkaro = solve(idx + 1, 1, limit, prices, dp);
            ans = max(buykaro, skipkaro);
        } else {
            int sellkaro =
                prices[idx] + solve(idx + 1, 1, limit - 1, prices, dp);
            int skipkaro = solve(idx + 1, 0, limit, prices, dp);
            ans = max(sellkaro, skipkaro);
        }
        return dp[idx][buy][limit] = ans;
    }


    int solveTab(vector<int>&prices){
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
                for(int limit = 1;limit<=2;limit++){

                    int ans = 0;
                    if (buy == 1) {
                        int buykaro = -prices[idx] + dp[idx+1][0][limit];
                        int skipkaro = dp[idx + 1][1][limit];
                        ans = max(buykaro, skipkaro);
                    } else {
                        int sellkaro =
                        prices[idx] + dp[idx + 1][1][limit - 1];
                        int skipkaro = dp[idx + 1][0][limit];
                        ans = max(sellkaro, skipkaro);
                    }   
                    dp[idx][buy][limit] = ans;
                }
            }
        }
        return dp[0][1][2];
    }
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        // return solve(0, 1, 2, prices, dp);

        return solveTab(prices);
    }
};