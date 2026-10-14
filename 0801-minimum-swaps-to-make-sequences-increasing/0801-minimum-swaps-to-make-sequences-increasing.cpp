class Solution {
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, bool swapped,
              vector<vector<int>>& dp) {
        if (idx == nums1.size()) {
            return 0;
        }
        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];
        if (dp[idx][swapped] != -1) {
            return dp[idx][swapped];
        }
        if (swapped) { // 1
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
        // no swap
        if (nums1[idx] > prev1 && nums2[idx] > prev2) {
            ans = solve(nums1, nums2, idx + 1, 0, dp);
        }
        // swap
        if (nums1[idx] > prev2 && nums2[idx] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, idx + 1, 1, dp));
        }
        return dp[idx][swapped] = ans;
    }

    int solveTab(vector<int>&nums1,vector<int>&nums2){
        int n = nums1.size();

        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int idx = n-1;idx>=1;idx--){
            for(int swapped = 1;swapped>=0;swapped--){
                int prev1 = nums1[idx-1];
                int prev2 = nums2[idx-1];
                
                if (swapped) { // 1
                    swap(prev1, prev2);
                }
                int ans = INT_MAX;
                // no swap
                if (nums1[idx] > prev1 && nums2[idx] > prev2) {
                    ans = dp[idx + 1][0];
                }
                // swap
                if (nums1[idx] > prev2 && nums2[idx] > prev1) {
                    ans = min(ans, 1 + dp[idx+1][1]);
                }
                dp[idx][swapped] = ans;

            }
        }
        return dp[1][0];
    };

    int solveSpace(vector<int>&nums1,vector<int>&nums2){
        int n = nums1.size();

        int swap = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;

        for(int idx = n-1;idx>=1;idx--){
            for(int swapped = 1;swapped>=0;swapped--){
                int prev1 = nums1[idx-1];
                int prev2 = nums2[idx-1];
                
                if (swapped) { // 1
                    int temp = prev1;
                    prev1 = prev2;
                    prev2 = temp;
                }
                int ans = INT_MAX;
                // no swap
                if (nums1[idx] > prev1 && nums2[idx] > prev2) {
                    ans = noswap;
                }
                // swap
                if (nums1[idx] > prev2 && nums2[idx] > prev1) {
                    ans = min(ans,1 + swap);
                }
                if(swapped){
                    currswap = ans;
                }
                else{
                    currnoswap = ans;
                }
            }
            swap = currswap;
            noswap = currnoswap;
        }
        return min(swap,noswap); 
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped, dp);

        // return solveTab(nums1,nums2);

        return solveSpace(nums1,nums2);
    }
};