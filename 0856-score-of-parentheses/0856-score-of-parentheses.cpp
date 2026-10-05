class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int>st;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '('){
                st.push(0);
            }
            else{
                // )
                if(st.top() == 0){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum = 0;
                    while(!st.empty() && st.top() != 0){
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(sum * 2);
                }
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};