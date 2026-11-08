class Solution {
    bool check(int i,int j,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        for(int row = 0;row<m;row++){
            if(grid[row][j] == 1 && row != i){
                return true;
            }
        }   
        for(int col = 0;col<n;col++){
            if(grid[i][col] == 1 && col != j){
                return true;
            }
        }

        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    bool result = check(i,j,grid);
                    if(result == true){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};