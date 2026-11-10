class Solution {
    int solve(int idx, vector<int>& costs, vector<int>& dp) {
        int n = costs.size();
        if (idx == n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        // i + 1
        int a = INT_MAX;
        if (idx + 1 <= n) {
            a = costs[idx] + 1 + solve(idx + 1, costs, dp);
        }

        // i + 2
        int b = INT_MAX;
        if (idx + 2 <= n) {
            b = costs[idx + 1] + 4 + solve(idx + 2, costs, dp);
        }

        // i + 3
        int c = INT_MAX;
        if (idx + 3 <= n) {
            c = costs[idx + 2] + 9 + solve(idx + 3, costs, dp);
        }

        return dp[idx] = min({a, b, c});
    }
    

    int solveTab(vector<int>& costs) {
        int n = costs.size();

        vector<int> dp(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {

            // i + 1
            int a = INT_MAX;
            if (idx + 1 <= n) {
                a = costs[idx] + 1 + dp[idx + 1];
            }

            // i + 2
            int b = INT_MAX;
            if (idx + 2 <= n) {
                b = costs[idx + 1] + 4 + dp[idx + 2];
            }

            // i + 3
            int c = INT_MAX;
            if (idx + 3 <= n) {
                c = costs[idx + 2] + 9 + dp[idx + 3];
            }

            dp[idx] = min({a, b, c});
        }
        return dp[0];
    }


    int solvespace(vector<int>&costs){
        int n = costs.size();

        int next1 = 0;
        int next2 = 0;
        int next3 = 0;
        int curr = 0;

        for(int idx = n-1;idx>=0;idx--){

            int a = INT_MAX;
            if(idx + 1 <= n){
                a = costs[idx] + 1 + next1;
            }

            int b = INT_MAX;
            if(idx + 2 <= n){
                b = costs[idx + 1] + 4 + next2;
            }

            int c = INT_MAX;
            if(idx + 3 <= n){
                c = costs[idx + 2] + 9 + next3;
            }

            curr = min({a,b,c});

            next3 = next2;
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        // vector<int>dp(n+1,-1);
        // return solve(0,costs,dp);

        // return solveTab(costs);

        return solvespace(costs);
    }
};