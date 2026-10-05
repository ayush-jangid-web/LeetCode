class Solution {
    int position(int target,int low,int high,vector<int>&nums){
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int solveDpBinary(vector<int>& nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int idx = position(nums[i],0,ans.size()-1,ans);
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }

    int solveMemo(int idx,int prev, vector<int>&nums,vector<vector<int>>&dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }
        
        int include = 0;
        if(prev == -1 || nums[prev] < nums[idx]){
            include = 1 + solveMemo(idx+1,idx,nums,dp);
        }

        int exclude = 0 + solveMemo(idx+1,prev,nums,dp);

        return dp[idx][prev+1] = max(include,exclude);
    }

    int solveTab(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int idx = n-1;idx>=0;idx--){
            for(int prev = idx-1;prev>=-1;prev--){
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

    int solveSpace(vector<int>&nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);

        for(int idx = n-1;idx>=0;idx--){
            for(int prev = idx-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || nums[prev] < nums[idx]){
                    include = 1 + nextRow[idx+1];
                }
                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include,exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solveDpBinary(nums);

        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));

        // return solveMemo(0,-1,nums,dp);

        // return solveTab(nums);

        // return solveSpace(nums);
    }
};