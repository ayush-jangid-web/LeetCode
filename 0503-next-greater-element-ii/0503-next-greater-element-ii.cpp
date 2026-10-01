class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>st;

        for(int i=(2*n)-1;i>=0;i--){
            int elem = nums[i%n];

            while(!st.empty() && st.top() <= elem){
                st.pop();
            }

            if(!st.empty()){
                ans[i%n] = st.top();
            }

            st.push(elem);
        }

        return ans;
    }
};