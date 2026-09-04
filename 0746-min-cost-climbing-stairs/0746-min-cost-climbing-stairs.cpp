class Solution {
    int solve(vector<int>&cost,int n){
        vector<int>dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }
    int solve2(vector<int>&cost,int n){
        int pre2 = cost[0];
        int pre1 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(pre1,pre2);
            pre2 = pre1;
            pre1 = curr;
        }

        return min(pre1,pre2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        return solve2(cost,n);
        
    }
};