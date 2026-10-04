class Solution {
    int position(int target,int low,int high,vector<int>&nums){
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int solveDpBinary(vector<int>& nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int idx = position(nums[i],0,ans.size()-1,ans);
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solveDpBinary(nums);
    }
};