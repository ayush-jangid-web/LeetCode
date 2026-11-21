class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            ans = max(ans,maxi + nums[i] - i);
            maxi = max(maxi,nums[i] + i);
        }

        return ans;
    }
};