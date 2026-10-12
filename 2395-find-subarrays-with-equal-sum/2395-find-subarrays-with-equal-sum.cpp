class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return false;
        }
        unordered_map<int,int>mp;
        int i = 0;
        int j = 1;

        while(i<n && j<n){
            int sum = 0;
            sum += nums[i++] + nums[j++];
            mp[sum]++;
            if(mp[sum] > 1){
                return true;
            }
        }

        return false;
    }
};