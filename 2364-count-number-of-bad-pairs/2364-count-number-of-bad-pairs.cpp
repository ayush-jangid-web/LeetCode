class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long good = 0;

        map<int,int>mp;
        for(int i=0;i<n;i++){
            int key = nums[i]-i;
            good += mp[key];
            mp[key]++;
        }
        long long total = 1LL * n*(n-1)/2;
        return total - good;
    }
};
