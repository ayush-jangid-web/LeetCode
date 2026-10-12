class Solution {
    bool solve(int n,int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0){
            return true;
        }
        if(target < 0 || idx >= n){
            return false;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        bool include = false;   
        if(target - nums[idx] >= 0){
            include = solve(n,idx+1,target-nums[idx],nums,dp);
        }
        bool exclude = solve(n,idx+1,target,nums,dp);

        return dp[idx][target] = (include || exclude);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totalsum = 0;
        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }

        if(totalsum % 2 != 0){
            return false;
        }

        int target = totalsum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        return solve(n,0,target,nums,dp);
    }
};