class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;

        for(int i=1;i<=n+1;i++){
            mp[k*i]++;
        }

        for(int i=0;i<n;i++){
            mp[nums[i]]--;
        }

        for(auto &it:mp){
            if(it.second > 0){
                return it.first;
            }
        }
        return -1;
    }
};