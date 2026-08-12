class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = 0;

        int i=0;
        int j=0;
        while(i<n && j<n){
            int elem = nums[j];
            mp[elem]++;
            while(mp[elem] > k){
                mp[nums[i]]--;
                i++;
            }    
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};