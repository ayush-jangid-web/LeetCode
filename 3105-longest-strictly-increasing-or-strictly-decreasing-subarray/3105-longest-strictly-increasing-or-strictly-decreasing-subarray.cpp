class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        int inc = 1;
        int dec = 1;

        int i = 0;
        int j = 0;

        while (i < n - 1 && j < n - 1) {
            if (nums[j] < nums[j + 1]) {
                j++;
            } else {
                i++;
                j = i;
            }
            inc = max(inc, j - i + 1);
        }

        i = 0;
        j = 0;
        while (i < n - 1 && j < n - 1) {
            if (nums[j] > nums[j + 1]) {
                j++;
            } else {
                i++;
                j = i;
            }
            dec = max(dec, j - i + 1);
        }

        return max(inc, dec);
    }
};