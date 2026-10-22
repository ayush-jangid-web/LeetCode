class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            st.push(s[i]);

            if (st.size() >= part.length()) {
                // cheak that if part matches

                // copy org stack with temp;
                stack<char> temp = st;
                bool isfound = true;

                for (int j = m - 1; j >= 0; j--) {
                    char top = temp.top();
                    temp.pop();
                    if (part[j] != top) {
                        isfound = false;
                        break;
                    }
                }

                if (isfound) {
                    int k = 0;
                    while (k < m) {
                        st.pop();
                        k++;
                    }
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};