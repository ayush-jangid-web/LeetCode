class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans = 0;

        for(int idx=0;idx<n;idx++){
            int elem = arr[idx] - difference;
            int temp = 0;
            if(dp.count(elem)){
                temp = dp[elem];
            }
            dp[arr[idx]] = 1 + temp; 
            ans = max(ans,dp[arr[idx]]);
        }
        return ans;
    }
};