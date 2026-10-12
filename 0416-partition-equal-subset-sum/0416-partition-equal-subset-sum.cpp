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


    bool solveTab(int n,int target,vector<int>&nums){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        for(int idx = 0;idx<=n;idx++){
            dp[idx][0] = 1;
        }

        for(int idx = n-1;idx>=0;idx--){
            for(int t=1;t<=target;t++){
                bool include = false;
                if(t - nums[idx] >= 0){
                    include = dp[idx+1][t-nums[idx]];
                }
                bool exclude = dp[idx+1][t];
            
                dp[idx][t] = (include || exclude);
            }
        }
        return dp[0][target];
    }


    bool solveSpace(int n,int target,vector<int>&nums){
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        next[0] = 1;
        curr[0] = 1;
        
        for(int idx = n-1;idx>=0;idx--){
            for(int t=1;t<=target;t++){
                bool include = false;
                if(t - nums[idx] >= 0){
                    include = next[t-nums[idx]];
                }
                bool exclude = next[t];
            
                curr[t] = (include || exclude);
            }
            next = curr;
        }
        return next[target];
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
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        // return solve(n,0,target,nums,dp);

        // return solveTab(n,target,nums);

        return solveSpace(n,target,nums);

    }
};