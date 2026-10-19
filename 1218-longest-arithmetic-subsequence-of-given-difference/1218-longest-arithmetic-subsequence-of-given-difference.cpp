class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        int ans = 0;
        unordered_map<int,int>dp;

        for(int i=0;i<n;i++){
            int elem = arr[i] - difference;
            int temp = 0;
            if(dp.count(elem)){
                temp = dp[elem];
            }
            dp[arr[i]] = temp + 1;
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};