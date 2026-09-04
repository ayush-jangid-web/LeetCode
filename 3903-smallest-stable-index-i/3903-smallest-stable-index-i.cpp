class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int>pre(n);
        vector<int>post(n);

        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            pre[i] = maxi;
        }
        
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            post[i] = mini;
        }

        for(int i=0;i<n;i++){
            if((pre[i] - post[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};