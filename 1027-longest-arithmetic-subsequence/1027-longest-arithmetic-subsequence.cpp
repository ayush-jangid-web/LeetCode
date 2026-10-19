class Solution {
    int solve(int idx,int diff,vector<int>&nums,unordered_map<int,int>dp[]){
        if(idx < 0){
            return 0;
        }
        if(dp[idx].count(diff)){
            return dp[idx][diff];
        }

        int ans = 0;
        for(int k=idx-1;k>=0;k--){
            if(nums[idx]-nums[k] == diff){
                ans = max(ans,1 + solve(k,diff,nums,dp));
            }
        }
        return dp[idx][diff] = ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        // idx ---- diff -> value
        unordered_map<int,int>dp[n+1];

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2 + solve(i,nums[j]-nums[i],nums,dp));
            }
        }
        return ans;
    }
};