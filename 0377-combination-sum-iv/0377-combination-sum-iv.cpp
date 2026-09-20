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
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1,-1);
        return solve(target,nums,dp);
    }
};