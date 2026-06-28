class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(),arr.end());
        arr[0] = 1;

        for(int i=1;i<n;i++){
            if((arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,arr[i]);
        }

        return ans;
    }
};