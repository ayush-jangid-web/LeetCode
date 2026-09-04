class Solution {
    int solveRec(vector<int>&coins,int k){
        if(k == 0){
            return 0;
        }
        if(k < 0){
            return INT_MAX;
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveRec(coins,k-coins[i]);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }

        return mini;
    }
    int solveMemo(vector<int>&coins,int k,vector<int>&dp){
        if(k == 0){
            return 0;
        }
        if(k < 0){
            return INT_MAX;
        }
        if(dp[k] != -1){
            return dp[k];
        }

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solveMemo(coins,k-coins[i],dp);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[k] = mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int>dp(amount+1,-1);
        int ans = solveMemo(coins,amount,dp);

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};