class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            string s = operations[i];

            if(s == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(s == "D"){
                st.push(st.top()*2);
            }
            else if(s == "C"){
                st.pop();
            }
            else{
                st.push(stoi(s));
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