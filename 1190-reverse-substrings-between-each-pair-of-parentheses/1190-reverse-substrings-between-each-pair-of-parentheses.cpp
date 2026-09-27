class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        queue<char> q;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == ')') {
                while (st.top() != '(') {
                    char top = st.top();
                    q.push(top);
                    st.pop();
                }

                if (st.top() == '(') {
                    st.pop();
                }

                while (!q.empty()) {
                    char elem = q.front();
                    st.push(elem);
                    q.pop();
                }

            } else {
                st.push(ch);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};