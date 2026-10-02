class Solution {
    int solve(int idx,int time,int n, vector<int>& nums, vector<vector<int>>&dp){
        if(idx == n){
            return 0;
        }
        if(dp[idx][time] != -1){
            return dp[idx][time];
        }

        int include = (nums[idx]*time) + solve(idx+1,time+1,n,nums,dp);
        int exclude = solve(idx+1,time,n,nums,dp);

        return dp[idx][time] = max(include,exclude);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,n,satisfaction,dp);
    }
};