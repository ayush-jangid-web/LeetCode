class Solution {
    int solve(int pos, int lane, vector<int>& obstacles,
              vector<vector<int>>& dp) {
        if (pos == obstacles.size() - 1) {
            return 0;
        }
        if (dp[pos][lane] != -1) {
            return dp[pos][lane];
        }

        if (obstacles[pos + 1] != lane) {
            // move forward;
            return dp[pos][lane] = solve(pos + 1, lane, obstacles, dp);
        } else {
            // change lane;
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != lane && obstacles[pos] != i) {
                    ans = min(ans, 1 + solve(pos, i, obstacles, dp));
                }
            }
            return dp[pos][lane] = ans;
        }
    }

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, 1e9));

        vector<int> prev(4, 1e9);
        vector<int> next(4, 1e9);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int pos = n - 2; pos >= 0; pos--) {
            for (int lane = 1; lane <= 3; lane++) {

                if (obstacles[pos + 1] != lane) {
                    prev[lane] = next[lane];
                } else {
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++) {
                        if (lane != i && obstacles[pos] != i) {
                            // pos+1 because we check for 1->2->3 in which 3rd
                            // lane ans not updated , so we have to check for
                            // the next pos+1
                            ans = min(ans, 1 + next[i]);
                        }
                    }

                    prev[lane] = ans;
                }
            }
            next = prev;
        }
        return next[2];
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // int n = obstacles.size();
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        // return solve(0,2,obstacles,dp);

        return solveTab(obstacles);
    }
};