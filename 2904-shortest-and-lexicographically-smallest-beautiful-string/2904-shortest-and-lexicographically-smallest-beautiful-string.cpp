class Solution {
    bool solve(string& ans, string& temp) {
        int n = ans.length();
        if (n == 0) {
            return true;
        }
        int m = temp.length();

        if (n == m) {
            int i = 0;
            while (i < n) {
                char a = ans[i];
                char t = temp[i];
                if (a == '1' && t == '0') {
                    return true;
                }
                if (a == '0' && t == '1') {
                    return false;
                }
                i++;
            }
            return true;
        }
        if (n < m) {
            return false;
        }
        if (n > m) {
            return true;
        }
        return false;
    }

public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";

        for (int i = 0; i < n; i++) {
            string temp = "";
            int one = 0;
            for (int j = i; j < n; j++) {
                char ch = s[j];
                temp += ch;
                if (ch == '1') {
                    one++;
                }
                if (one == k) {
                    if (solve(ans, temp)) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};