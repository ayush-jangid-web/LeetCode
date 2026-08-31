class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int ans = INT_MAX;
        int cnt = 0;

        unordered_map<int, int> mp;

        int i = 0;

        for (int j = 0; j < n; j++) {
            int val = cards[j];

            mp[val]++;
            cnt++;
            while (mp[val] > 1) {
                ans = min(ans, cnt);
                mp[cards[i]]--;
                i++;
                cnt--;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};