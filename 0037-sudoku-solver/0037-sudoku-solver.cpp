class Solution {
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
        for(int i=0;i<9;i++){
            //row
            if(board[i][col] == val){
                return false;
            }
            if(board[row][i] == val){
                return false;
            }
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col] == '.'){
                    for(int i=1;i<=9;i++){
                        char val = char(i+'0');
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;

                            bool nextSol = solve(board);
                            if(nextSol == true){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    };
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board);
    }
};