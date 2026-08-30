class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a']++;
        }

        sort(mp.begin(), mp.end(), greater<int>());
        int cnt = 0;
        for (auto& i : mp) {
            cnt += i;
        }
        for (int i = 1; i < 26; i++) {
            while ((mp[i] >= mp[i - 1]) && mp[i] > 0) {
                mp[i]--;
            }
        }
        int ans = 0;
        for (auto& i : mp) {
            ans += i;
        }
        return cnt - ans;
    }
};