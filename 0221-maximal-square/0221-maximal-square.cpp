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

    int solveTab(vector<vector<char>>&matrix,int& maxi){
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>>dp(row+1,vector<int>(col+1,0));

        for(int i = row-1;i>=0;i--){
            for(int j = col-1;j>=0;j--){

                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    int ans = 1 + min({right,diagonal,down});
                    maxi = max(ans,maxi);
                    dp[i][j] = ans;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int solveOpt(vector<vector<char>>&matrix,int& maxi){
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>curr(col+1);
        vector<int>next(col+1);

        for(int i = row-1;i>=0;i--){
            for(int j = col-1;j>=0;j--){

                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(matrix[i][j] == '1'){
                    int ans = 1 + min({right,diagonal,down});
                    maxi = max(ans,maxi);
                    curr[j] = ans;
                }
                else{
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
public:
    int maximalSquare(vector<vector<char>>&matrix) {
        int maxi = 0;
        // vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        // solve(0,0,matrix,maxi,dp);
        // solveTab(matrix,maxi);
        solveOpt(matrix,maxi);
        return maxi*maxi;
    }
};