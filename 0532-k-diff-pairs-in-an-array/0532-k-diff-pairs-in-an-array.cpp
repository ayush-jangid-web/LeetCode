class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        if (k == 0) {
            int ans = 0;
            for (auto& it : mp) {
                if (it.second > 1) {
                    ans++;
                }
            }
            return ans;
        }

        // k!=0
        int ans = 0;
        for(auto &it:mp){
            if(mp.count(it.first + k)){
                ans++;
            }
        }
        return ans;
    }
};