class Solution {
    int solve(vector<int>&nums,int k,int n,vector<int>&dp){
        if(n < k){
            return 0;
        }
        if( n == k){
            return nums[k];
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int include = solve(nums,k,n-2,dp) + nums[n];
        int exclude = solve(nums,k,n-1,dp) + 0;

        return dp[n] = max(include,exclude);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        return max(
            solve(nums,0,n-2,dp1),
            solve(nums,1,n-1,dp2)
        );
    }
};