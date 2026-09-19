class Solution {
    bool solve(int target, int i, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (i < 0 || target < 0) {
            return false;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        // include
        bool include = false;
        if (nums[i] <= target) {
            include = solve(target - nums[i], i - 1, nums, dp);
        }
        // exclude
        bool exclude = solve(target, i - 1, nums, dp);

        return dp[i][target] = (include || exclude);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(target, n - 1, nums, dp);
    }
};