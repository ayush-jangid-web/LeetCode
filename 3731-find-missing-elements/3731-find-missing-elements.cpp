class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;

        int n = nums.size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]] = 1;
            low = min(nums[i],low);
            high = max(nums[i],high);
        }

        for(int i=low;i<=high;i++){
            mp[i]--;
        }

        for(auto &it:mp){
            if(it.second == -1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};