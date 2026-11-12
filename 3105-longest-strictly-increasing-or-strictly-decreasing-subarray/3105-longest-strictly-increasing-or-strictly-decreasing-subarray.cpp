class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;
        int dec = 1;

        for (int i = 0; i < n-1; i++) {
            int tempinc = 1;

            int p = i;
            int q = i + 1;
            while (p < n && q < n) {
                if (nums[p] < nums[q]) {
                    tempinc++;
                }
                else {
                    tempinc = 1;
                }
                inc = max(inc, tempinc);
                p++;
                q++;
            }
        }


        for (int i = 0; i < n ; i++) {
            int tempdec = 1;

            int p = i;
            int q = i + 1;
            while (p < n && q < n) {
                if (nums[p] > nums[q]) {
                    tempdec++;
                }
                else {
                    tempdec = 1;
                }
                dec = max(dec, tempdec);
                p++;
                q++;
            }
        }

        return max(inc, dec);
    }
};