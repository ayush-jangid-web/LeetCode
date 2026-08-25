class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(int i=k;;i+=k){
            if(mp[i] == 0){
                return i;
            }
        }
        return -1;
    }
};