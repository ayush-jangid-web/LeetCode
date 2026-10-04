class Solution {
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

    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){

                int include = 0;
                if(prev == -1 || nums[prev] < nums[idx]){
                    include = 1 + dp[idx+1][idx+1];
                }
                int exclude = 0 + dp[idx+1][prev+1];

                dp[idx][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,nums,dp);

        return solveTab(nums);
    }
};