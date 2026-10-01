class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int,int>mp;
        stack<int>st;
        st.push(-1);

        for(int i=n2-1;i>=0;i--){
            int elem = nums2[i];

            while(!st.empty() && st.top() <= elem){
                st.pop();
            }

            if(st.empty()){
                mp[elem] = -1;
            }
            else{
                mp[elem] = st.top();
            }

            st.push(elem);
        }

        vector<int>ans;
        for(int i=0;i<n1;i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};