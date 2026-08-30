class Solution {
    int solve(int maxidx, int minidx, int n){
        //left to right;
        int p = max(minidx,maxidx);
        int a = p + 1;

        //right to left;
        int q = min(minidx,maxidx);
        int b = n - q;

        //both side;
        int c = (n-p) + (q+1);

        return min(a,min(b,c));
    }
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }

        int minidx = -1;
        int maxidx = -1;

        for(int i=0;i<n;i++){
            if(nums[i] == mini){
                minidx = i;
            }
            if(nums[i] == maxi){
                maxidx = i;
            }
        }

        return solve(maxidx,minidx,n);
    }
};