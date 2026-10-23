class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        bool flag = true;
        for(int i=0;i<n;i++){
            if(nums[i] != i){
                flag = false;
                ans = ans & nums[i];
            }
        }
        if(flag == true){
            return 0;
        }
        return ans;

    }
};