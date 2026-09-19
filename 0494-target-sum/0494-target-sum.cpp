class Solution {
    int solve(int target,int i,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        int include = 0;
        if(nums[i] <= target){
            include = solve(target-nums[i],i-1,nums,dp);
        }
        int exclude = solve(target,i-1,nums,dp);

        return dp[i][target] = include + exclude;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }

        if( (totalsum - abs(target)) < 0 || (totalsum - abs(target))%2 != 0){
            return 0;
        }
        int s2 = (totalsum + target)/2;

        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return solve(s2,n-1,nums,dp);
    }
};