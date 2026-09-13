class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        map<pair<int,int>,int>count;
        vector<pair<int,int>>a;
        vector<pair<int,int>>b;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1){
                    a.push_back({i,j});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img2[i][j] == 1){
                    b.push_back({i,j});
                }
            }
        }

        for(auto &i:a){
            for(auto &j:b){
                int x = j.first - i.first; 
                int y = j.second - i.second;

                count[{x,y}]++; 
            }
        }

        int ans = 0;
        for(auto &it:count){
            ans = max(ans,it.second);
        }
        return ans;
        
    }
};