class Solution {
    string solvecount(string s) {
        int n = s.length();
        vector<vector<char>> mp;
        if (n == 0) {
            return "";
        }

        int i = 0;
        int j = 0;
        string result = "";
        while (i < n && j < n) {
            int cnt = 0;
            while (j < n && s[i] == s[j]) {
                cnt++;
                j++;
            }
            result += to_string(cnt);
            result += s[i];
            i = j;
        }
        return result;
    }

public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++) {
            result = solvecount(result);
        }
        return result;
    }
};