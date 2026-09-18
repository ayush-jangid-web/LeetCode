class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> zeros;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    continue;
                }

                int mini = INT_MAX;

                for (auto& it : zeros) {
                    int a = it.first;
                    int b = it.second;

                    int dis = abs(i - a) + abs(j - b);
                    mini = min(mini, dis);
                }
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};