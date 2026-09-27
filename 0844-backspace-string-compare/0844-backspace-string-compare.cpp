class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();

        stack<char> st1;
        stack<char> st2;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '#') {
                if (!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(ch);
            }
        }

        for (int i = 0; i < m; i++) {
            char ch = t[i];
            if (ch == '#') {
                if (!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(ch);
            }
        }

        if (st1.size() != st2.size()) {
            return false;
        }

        while (!st1.empty() && !st2.empty()) {
            char ch1 = st1.top();
            char ch2 = st2.top();

            if (ch1 != ch2) {
                return false;
            }

            st1.pop();
            st2.pop();
        }
        return true;
    }
};