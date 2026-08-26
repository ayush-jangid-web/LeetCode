class Solution {
    bool solve(string& ans, string& temp) {
        if(ans.length() == 0){return true;}

        if(ans.length() < temp.length()){return false;}
        if(ans.length() > temp.length()){return true;}

        if(temp < ans){return true;}
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