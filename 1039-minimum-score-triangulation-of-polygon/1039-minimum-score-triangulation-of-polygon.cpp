class Solution {
    int solve(int i,int j,vector<int>&values,vector<vector<int>>&dp){
        if(i+1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i+1;k<j;k++){
            int ans = (values[i]*values[k]*values[j]) + solve(i,k,values,dp) + solve(k,j,values,dp);
            mini = min(ans,mini);
        }
        return dp[i][j] = mini;
    }

    int solveTab(vector<int>&val){
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int mini = INT_MAX;
                for(int k = i+1;k<j;k++){
                    int ans = (val[i]*val[k]*val[j]) + dp[i][k] + dp[k][j];
                    mini = min(ans,mini); 
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][n-1];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        // int n = values.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(0,n-1,values,dp);

        return solveTab(values);
    }
};