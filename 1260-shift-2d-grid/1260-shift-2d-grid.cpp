class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>temp;
        vector<int>temp2;

    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }

        k %= (n * m);
        for(int i=0;i<n*m;i++){
            temp2.push_back(temp[(i+(n*m-k))%(n*m)]);
        }

        int p=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = temp2[p++];
            }
        }
        
        return grid;
    }
};