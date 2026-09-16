class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long ans = 0;

        if (n == 3 && m == 3) {
            return grid[0][0] + grid[0][1] + grid[0][2] + grid[1][1] +
                   grid[2][0] + grid[2][1] + grid[2][2];
        }

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                long long temp = (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                                  grid[i + 1][j + 1] + grid[i + 2][j] +
                                  grid[i + 2][j + 1] + grid[i + 2][j + 2]);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};