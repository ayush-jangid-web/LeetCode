class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n);
        vector<int>post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],nums[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            post[i] = min(post[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if((pre[i] - post[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};