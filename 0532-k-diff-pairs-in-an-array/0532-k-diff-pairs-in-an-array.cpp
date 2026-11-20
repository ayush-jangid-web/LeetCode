class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        if(k == 0){
            int ans = 0;
            for(auto &it:mp){
                if(it.second > 1){
                    ans++;
                }
            }
            return ans;
        }

        // k != 0
        vector<int>temp;
        for(auto &it:mp){
            temp.push_back(it.first);
        }

        int ans = 0;
        int m = temp.size();
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(abs(temp[i] - temp[j]) == k && i != j){
                    ans++;
                }
            }
        }

        return ans;
    }
};