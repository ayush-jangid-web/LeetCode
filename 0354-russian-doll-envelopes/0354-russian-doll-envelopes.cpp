class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }

    int position(int target, int start, int end, vector<int>& nums) {
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > ans.back()) {
                ans.push_back(envelopes[i][1]);
            } else {
                int idx = position(envelopes[i][1], 0, ans.size()-1, ans);
                ans[idx] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};