class Solution {
    int countdigit(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt++;
            num /= 10;
        }
        return cnt;
    }

public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (countdigit(nums[i]) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};