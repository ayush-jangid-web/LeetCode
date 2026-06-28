class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());

        long long totalsum = 0;
        for(int i=0;i<k;i++){
            int n = nums[i];
            if(mul > 0){
                totalsum += 1LL * n * mul;
                mul--;
            }else{
                totalsum += n;
            }
        }

        return totalsum;
    }
};