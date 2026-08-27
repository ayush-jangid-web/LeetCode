class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                int j = n-1;
                while(j > i){
                    if(nums[i] < nums[j]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                    j--;
                }

                sort(nums.begin()+i+1,nums.end());
                break;
            }
        }
        if(idx == -1){
            sort(nums.begin(),nums.end());
        }
    }
};