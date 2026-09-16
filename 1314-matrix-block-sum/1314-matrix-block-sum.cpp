class Solution {
    int solve(int i, int j, vector<vector<int>>& mat, int k, int n, int m) {
        int sum = 0;
        int s1 = max(0, i - k);
        int e1 = min(i + k, n - 1);
        int s2 = max(0, j - k);
        int e2 = min(j + k, m - 1);

        for (int r = s1; r <= e1; r++) {
            for (int c = s2; c <= e2; c++) {
                sum += mat[r][c];
            }
        }

        return sum;
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = solve(i, j, mat, k, n, m);
            }
        }

        return ans;
    }
};