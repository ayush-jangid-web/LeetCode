class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> mp(26);

        for (int i = 0; i < n; i++) {
            mp[word[i] - 'a']++;
        }

        sort(mp.begin(), mp.end(), greater<int>());

        int k = 1;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (k <= 8) {
                ans += (mp[i] * 1);
            } else if (k > 8 && k <= 16) {
                ans += (mp[i] * 2);
            } else if (k > 16 && k <= 24) {
                ans += (mp[i] * 3);
            } else {
                ans += (mp[i] * 4);
            }
            k++;
        }
        return ans;
    }
};