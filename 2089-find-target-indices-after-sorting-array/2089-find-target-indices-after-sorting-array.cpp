class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int less = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < target){
                less++;
            }
            if(nums[i] == target){
                cnt ++;
            }
        }
        vector<int>ans;
        if(cnt == 0){
            return ans;
        }
        for(int i=0;i<cnt;i++){
            ans.push_back(less+i);
        }
        return ans;
    }
};