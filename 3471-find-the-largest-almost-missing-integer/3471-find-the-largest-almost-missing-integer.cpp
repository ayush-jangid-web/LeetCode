class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int ans = -1;
        if (k == 1) {

            for (auto& i : mp) {
                if (i.second == 1) {
                    ans = max(ans, i.first);
                }
            }
            return ans;
        }
        else if (k == n) {

            for (auto& i : mp) {
                ans = max(ans, i.first);
            }
            return ans;
        }
        else {
            if (mp[nums[0]] == 1) {
                ans = max(ans, nums[0]);
            }
            if (mp[nums[n - 1]] == 1) {
                ans = max(ans, nums[n - 1]);
            }
            return ans;
        }
    }
};