class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        int k = total - x;
        if (k == 0) {
            return n;
        }
        if(k < 0){
            return -1;
        }
        int i = 0;
        int j = 0;
        int cnt = INT_MIN;
        int sum = 0;
        while (j < n) {
            sum += nums[j++];
            while (sum >= k && i < j) {
                if (sum == k) {
                    cnt = max(cnt, j - i);
                }
                sum -= nums[i++];
            }
        }

        if (cnt == INT_MIN) {
            return -1;
        }
        return n - cnt;
    }
};