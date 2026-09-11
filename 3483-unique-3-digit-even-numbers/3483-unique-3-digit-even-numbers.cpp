class Solution {
    int ans = 0;
    void solve(vector<int>& freq, int i, int num) {
        if (i == 3) {
            if (num % 2 == 0) {
                ans++;
            }
            return;
        }

        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (freq[j] > 0) {
                freq[j]--;
                solve(freq, i + 1, (num * 10) + j);
                freq[j]++;
            }
        }
    }

public:
    int totalNumbers(vector<int>& digits) {
        ans = 0;
        vector<int> freq(10, 0);
        for (int i = 0; i < digits.size(); i++) {
            freq[digits[i]]++;
        }
        solve(freq, 0, 0);
        return ans;
    }
};