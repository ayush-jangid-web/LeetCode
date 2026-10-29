class Solution {
    // recursion - TLE
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
              int right) {
        if (left == right) {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, ((maxi[{left, i}] * maxi[{i + 1, right}]) +
                            solve(arr, maxi, left, i) +
                            solve(arr, maxi, i + 1, right)));
        }
        return ans;
    }

    // Recursion + Memoization
    int solveMemo(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
                  int right, vector<vector<int>>& dp) {
        if (left == right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solveMemo(arr, maxi, left, i, dp) +
                               solveMemo(arr, maxi, i + 1, right, dp));
        }
        return dp[left][right] = ans;
    }

    // Tabulation
    int solveTab(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int left = n - 1; left >= 0; left--) {
            for (int right = left; right < n; right++) {
                if(right == left){
                    continue;
                }
                int ans = INT_MAX;
                for (int i = left; i < right; i++) {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                                       dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n - 1];
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i; j < n; j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }

        // return solve(arr,maxi,0,n-1);

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveMemo(arr, maxi, 0, n - 1, dp);

        return solveTab(arr,maxi);
    }
};