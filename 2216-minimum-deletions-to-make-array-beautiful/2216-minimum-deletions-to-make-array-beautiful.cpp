class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        int ans = 0;
        int count = 0;
        for (auto x : nums) {

            if (count % 2 == 1) {
                if (prev == x) {
                    ans++;
                    continue;
                }
            }
            prev = x;
            count++;
        }
        if (count % 2 == 0) {
            return ans;
        }
        return ans + 1;
    }
};