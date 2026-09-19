class Solution {

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            int u = boxTypes[i][0];
            int v = boxTypes[i][1];

            temp.push_back({u,v});
        }

        sort(temp.begin(),temp.end(),[](const auto &a,const auto &b){
            return a.second > b.second;
        });

        int ans = 0;
        for(int i=0;i<n;i++){
            int u = temp[i].first;
            int v = temp[i].second;

            if(u <= truckSize && truckSize != 0){
                ans += (u*v);
                truckSize -= u;
            }
            else if(u > truckSize && truckSize != 0){
                int unit = truckSize;
                ans += unit*v;
                truckSize = 0;
            }
        }
        return ans;
    }
};