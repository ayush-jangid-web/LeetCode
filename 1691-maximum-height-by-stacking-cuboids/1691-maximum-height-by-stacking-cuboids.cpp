class Solution {
    bool check(vector<int>& prev, vector<int>& next) {
        if ((prev[0] >= next[0]) && (prev[1] >= next[1]) && (prev[2] >= next[2])) {
            return true;
        }
        return false;
    }
    int solve(int n, vector<vector<int>>& cuboids) {
        vector<int> nextRow(n + 1, 0);
        vector<int> currRow(n + 1, 0);

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {
                int include = 0;
                if (prev == -1 || check(cuboids[idx],cuboids[prev])) {
                    include = cuboids[idx][2] + nextRow[idx + 1];
                }
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        // sort each cuboids, such that max element came at end, which becomes
        // height.
        for (int i = 0; i < n; i++) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        // sort all cuboids on the bases of their base;
        sort(cuboids.begin(), cuboids.end());

        // now this q becomes of longest decreasing subsequence
        return solve(n, cuboids);
    }
};