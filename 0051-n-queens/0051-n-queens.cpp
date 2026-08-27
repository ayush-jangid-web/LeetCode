class Solution {
    unordered_map<int,bool>leftrow;
    unordered_map<int,bool>upperdia;
    unordered_map<int,bool>lowerdia;

    void saveans(vector<vector<int>>&board,vector<vector<string>>&ans,int n){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string s = "";
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    s += "Q";
                }
                else{
                    s += ".";
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    bool issafe(int row, int col, int n){
        // row
        if(leftrow[row] == true){
            return false;
        }

        // upperdia
        if(upperdia[n-1+col-row] == true){
            return false;
        }
        //lowerdia
        if(lowerdia[row+col] == true){
            return false;
        }

        return true;
    }

    void solve(int col,vector<vector<string>>& ans,vector<vector<int>>& board,int n){
        if(col == n){
            saveans(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(issafe(row,col,n)){
                leftrow[row] = true;
                upperdia[n-1+col-row] = true;
                lowerdia[row+col] = true;
                board[row][col] = 1;

                solve(col+1,ans,board,n);

                board[row][col] = 0;
                lowerdia[row+col] = false;
                upperdia[n-1+col-row] = false;
                leftrow[row] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>>board(n,vector<int>(n,0));

        solve(0,ans,board,n);
        return ans;
    }
};