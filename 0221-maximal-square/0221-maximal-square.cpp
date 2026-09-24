class Solution {
    int solve(int i,int j,vector<vector<char>>& matrix,int& maxi,vector<vector<int>>&dp){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int left = solve(i,j+1,matrix,maxi,dp);
        int diagonal = solve(i+1,j+1,matrix,maxi,dp);
        int down = solve(i+1,j,matrix,maxi,dp);

        if(matrix[i][j] == '1'){
            int ans = 1 + min({left,diagonal,down});
            maxi = max(ans,maxi);
            return dp[i][j] = ans;
        }
        else{
            return dp[i][j] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        solve(0,0,matrix,maxi,dp);
        return maxi*maxi;
    }
};