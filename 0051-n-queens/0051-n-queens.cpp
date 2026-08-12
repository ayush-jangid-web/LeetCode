class Solution {
    unordered_map<int, bool> leftRow;
    unordered_map<int, bool> upperDia;
    unordered_map<int, bool> lowerDia;

    void saveans(vector<vector<string>>& ans, vector<vector<int>>& board,
                 int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    s += ".";
                } else {
                    s += "Q";
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, int n) {
        // row
        if (leftRow[row] == true) {
            return false;
        }

        // diagonal up
        if (upperDia[n - 1 + col - row] == true) {
            return false;
        }

        // diagonal down
        if (lowerDia[row + col] == true) {
            return false;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board,
               int n) {
        if (col == n) {
            saveans(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n)) {
                leftRow[row] = true;
                upperDia[n - 1 + col - row] = true;
                lowerDia[row + col] = true;
                board[row][col] = 1;

                solve(col + 1, ans, board, n);

                board[row][col] = 0;
                leftRow[row] = false;
                upperDia[n - 1 + col - row] = false;
                lowerDia[row + col] = false;
            }
        }
    };

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));

        solve(0, ans, board, n);
        return ans;
    }
};