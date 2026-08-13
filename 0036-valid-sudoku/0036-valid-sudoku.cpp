class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        for(int i=0;i<9;i++){
            unordered_map<int,int>rowmp;
            unordered_map<int,int>colmp;
            for(int j=0;j<9;j++){
                //row
                if(board[i][j] != '.')
            
                    if(rowmp[ board[i][j] ] < 1){
                        rowmp[ board[i][j] ]++;
                    }else{
                        return false;
                    }

                //col
                if(board[j][i] != '.')
                    if(colmp[ board[j][i] ] < 1){
                        colmp[ board[j][i] ]++;
                    }else{
                        return false;
                    }
            }
        }

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                unordered_map<int,int>matrixmp;
                
                for(int i=0;i<9;i++){
                    if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == '.')
                        continue;
                    if(matrixmp[board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]] < 1){
                        matrixmp[board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]]++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};