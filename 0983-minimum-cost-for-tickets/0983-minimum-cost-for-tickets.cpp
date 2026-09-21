class Solution {
    int solve(int idx, vector<int>& days, vector<int>& costs, vector<int>&dp) {
        if (idx >= days.size()) {
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        // 1 day pass
        int pass1 = costs[0] + solve(idx + 1, days, costs, dp);

        // 7 days pass
        int j;
        for (j = idx; j < days.size() && days[j] < days[idx] + 7; j++)
            ;
        int pass7 = costs[1] + solve(j, days, costs, dp);

        // 30 days pass
        for (j = idx; j < days.size() && days[j] < days[idx] + 30; j++)
            ;
        int pass30 = costs[2] + solve(j, days, costs, dp);

        return dp[idx] = min({pass1, pass7, pass30});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return solve(0, days, costs, dp);
    }
};