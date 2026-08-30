class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int i = 0;
        int ans = 0;
        while (i < n) {
            int a = nums[i];
            if (st.size() == 0) {
                st.push(a);
            } else if (st.size() % 2 != 0) {
                int top = st.top();
                st.pop();

                if (top == a) {
                    ans++;
                    st.push(top);
                } else {
                    st.push(top);
                    st.push(a);
                }
            } else {
                st.push(a);
            }
            i++;
        }

        if (st.size() % 2 == 0) {
            return ans;
        } else {
            return ans + 1;
        }
    }
};