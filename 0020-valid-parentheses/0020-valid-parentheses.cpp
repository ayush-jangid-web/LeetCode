class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char ch = st.top();
                    if(s[i] == ')' && ch == '('){
                        st.pop();
                    }
                    else if(s[i] == '}' && ch == '{'){
                        st.pop();
                    }
                    else if(s[i] == ']' && ch == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};