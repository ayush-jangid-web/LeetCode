class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                ans += mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};