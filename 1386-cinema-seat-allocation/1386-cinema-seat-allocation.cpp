class Solution {
    void solve(unordered_map<int, list<int>>& seat, int& cnt) {
        int ans = 0;
        for (auto i : seat) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (auto j : i.second) {
                if (j > 1 && j < 6) {
                    left = false;
                }
                if (j > 3 && j < 8) {
                    middle = false;
                }
                if (j > 5 && j < 10) {
                    right = false;
                }
            }
            if (left && right) {
                ans += 2;
            } else if (left || right || middle) {
                ans += 1;
            }
        }
        cnt += ans;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int cnt = 0;
        int m = reservedSeats.size();

        int row_count = 0;

        unordered_map<int, list<int>> seat;

        for (int i = 0; i < m; i++) {

            int u = reservedSeats[i][0];
            int v = reservedSeats[i][1];
            seat[u].push_back(v);
        }

        solve(seat, cnt);

        for (auto& it : seat) {
            if (it.second.size() != 0) {
                row_count++;
            }
        }

        cnt += (n - row_count) * 2;
        return cnt;
    }
};