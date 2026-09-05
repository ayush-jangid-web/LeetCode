class Solution {
    int solve(vector<int>&nums,int n,vector<int>&dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        if(dp[n]!= -1){
            return dp[n];
        }

        int h1 = solve(nums,n-2,dp) + nums[n];
        int h2 = solve(nums,n-1,dp) + 0;

        dp[n] = max(h1,h2);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};