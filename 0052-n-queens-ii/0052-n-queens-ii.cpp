class Solution {
    unordered_map<int, bool> leftrow;
    unordered_map<int, bool> upperdia;
    unordered_map<int, bool> lowerdia;

    bool issafe(int row, int col, int n) {
        if (leftrow[row] == true) {
            return false;
        }
        if (upperdia[n - 1 + col - row] == true) {
            return false;
        }
        if (lowerdia[row + col] == true) {
            return false;
        }

        return true;
    }

    void solve(int col, vector<vector<int>> & board, int& ans, int n) {
        if (col == n) {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (issafe(row, col, n)) {
                board[row][col] = 1;
                leftrow[row] = true;
                upperdia[n - 1 + col - row] = true;
                lowerdia[row + col] = true;

                solve(col + 1, board, ans, n);

                board[row][col] = 0;
                leftrow[row] = false;
                upperdia[n - 1 + col - row] = false;
                lowerdia[row + col] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));

        // col,board,ans,n
        solve(0, board, ans, n);
        return ans;
    }
};