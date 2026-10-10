class Solution {
    int solve(int idx,int endidx,int n, vector<int>&slices,vector<vector<int>>&dp){
        if(n == 0 || idx > endidx){
            return 0;
        }
        if(dp[idx][n] != -1){
            return dp[idx][n];
        }

        int include = slices[idx] + solve(idx+2,endidx,n-1,slices,dp);
        int exclude = 0 + solve(idx+1,endidx,n,slices,dp);

        return dp[idx][n] = max(include,exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>>dp1(k,vector<int>(k,-1));
        vector<vector<int>>dp2(k,vector<int>(k,-1));

        int a = solve(0,k-2,k/3,slices,dp1);
        int b = solve(1,k-1,k/3,slices,dp2);

        return max(a,b);
    }
};