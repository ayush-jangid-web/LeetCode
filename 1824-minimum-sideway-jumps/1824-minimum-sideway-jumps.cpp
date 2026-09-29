class Solution {
    int solve(int pos,int lane,vector<int>&obstacles,vector<vector<int>>&dp){
        if(pos == obstacles.size()-1){
            return 0;
        }
        if(dp[pos][lane] != -1){
            return dp[pos][lane];
        }

        if(obstacles[pos+1] != lane){
            //move forward;
            return dp[pos][lane] = solve(pos+1,lane,obstacles,dp);
        }
        else{
            //change lane;
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i != lane && obstacles[pos] != i){
                    ans = min(ans,1+solve(pos,i,obstacles,dp));
                }
            }
            return dp[pos][lane]= ans;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(0,2,obstacles,dp);
    }
};