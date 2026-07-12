class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]] = 0 ;
        }
        int i = 1;
        for(auto &it:mp){
            it.second = i++;
        }

        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};