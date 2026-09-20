class Solution {
    int solve(int target,vector<int>&nums,vector<int>&dp){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int include = 0;
        for(int i=0;i<nums.size();i++){
            include += solve(target-nums[i],nums,dp);
        }
        return dp[target] = include;
    }

    int solveTab(int target,vector<int>&nums){
        vector<unsigned int>dp(target+1,0);

        dp[0] = 1;

        int count = 0;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j] >= 0){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int>dp(target+1,-1);
        // return solve(target,nums,dp);
        return solveTab(target,nums);
    }
};