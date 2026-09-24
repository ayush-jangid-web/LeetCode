class Solution {
    int solve(int num){
        int sum = 0;
        while(num!=0){
            int d = num%10;
            sum += d;
            num/=10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int num = nums[i];
            if(solve(num) == i){
                ans = min(ans,i);
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};