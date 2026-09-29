class Solution {
    bool solve(int i,int j,int bal,vector<vector<char>>&grid,
    vector<vector<vector<int>>>&dp){
        int n = grid.size();
        int m = grid[0].size();

        if(grid[i][j] == '('){
            bal++;
        }
        else{
            bal--;
        }

        if( i == n-1 && j == m-1){
            return bal == 0;
        }
        if(bal < 0){
            return false;
        }
        if(dp[i][j][bal] != -1){
            return dp[i][j][bal];
        }

        //down
        bool down = false;
        if(i+1 < n){
            down = solve(i+1,j,bal,grid,dp);
        }

        //right
        bool right = false;
        if(j+1 < m){
            right = solve(i,j+1,bal,grid,dp);
        }

        return dp[i][j][bal] = right || down;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        return solve(0,0,0,grid,dp);
    }
};