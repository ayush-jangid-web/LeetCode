class Solution {
    int solve(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(idx >= days.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int pass1 = costs[0] + solve(idx+1,days,costs,dp);

        int j ;
        for(j = idx; j<days.size() && days[j] < days[idx] + 7; j++);
        int pass7 = costs[1] + solve(j,days,costs,dp);

        for(j = idx;j<days.size() && days[j] < days[idx] + 30;j++);
        int pass30 = costs[2] + solve(j,days,costs,dp);

        return dp[idx] = min({pass1,pass7,pass30});
    }

    int solveTab(vector<int>&days,vector<int>&costs){
        int n = days.size();
        vector<int>dp(n+1,INT_MAX);

        dp[n] = 0;
        for(int idx = n-1;idx>=0;idx--){
            int pass1 = costs[0] + dp[idx+1];

            int j;
            for(j = idx;j<n && days[j] < days[idx]+7;j++);
            int pass7 = costs[1] + dp[j];
            
            for(j = idx;j<n && days[j] < days[idx]+30;j++);
            int pass30 = costs[2] + dp[j];

            dp[idx] = min({pass1,pass7,pass30});
        }
        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int>dp(days.size()+1,-1);
        // return solve(0,days,costs,dp);

        return solveTab(days,costs);
    }
};