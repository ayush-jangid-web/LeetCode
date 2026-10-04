class Solution {
    int ans = 0;
    int solve(int idx,int pre,vector<int>&nums,vector<vector<int>>&dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][pre+1] != -1){
            return dp[idx][pre+1];
        }

        int include = 0;
        if(pre == -1 || nums[pre] < nums[idx]){
            include = 1 + solve(idx+1,idx,nums,dp);
        }
        int exclude = solve(idx+1,pre,nums,dp);

        return dp[idx][pre+1] = max(include,exclude);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};