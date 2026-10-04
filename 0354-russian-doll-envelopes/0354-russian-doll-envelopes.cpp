class Solution {
    int position(int target,int start,int end,vector<int>&nums){
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] >= target){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 1. sort arr[0] -> ascending
        //         arr[1] -> decending

        int n = envelopes.size();

        sort(envelopes.begin(),envelopes.end(), [](const vector<int>&a,vector<int>&b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }

            return a[1] > b[1];
        });

        vector<int>ans;
        ans.push_back(envelopes[0][1]);

        for(int i=0;i<n;i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int idx = position(envelopes[i][1],0,ans.size(),ans);
                ans[idx] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};