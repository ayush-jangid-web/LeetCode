class Solution {
    int solve(vector<int>&nums,int n,vector<int>&dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[n];
        }

        if(dp[n]!= -1){
            return dp[n];
        }

        int include = solve(nums,n-2,dp) + nums[n]; 
        int exclude = solve(nums,n-1,dp) + 0;

        dp[n] = max(include,exclude);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,n-1,dp);
    }
};