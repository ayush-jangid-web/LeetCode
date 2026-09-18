class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>pmax(n);
        vector<int>smin(n);

        pmax[0] = arr[0];
        smin[n-1] = arr[n-1];

        for(int i=1;i<n;i++){
            pmax[i] = max(pmax[i-1],arr[i]);
        }

        for(int i=n-2;i>=0;i--){
            smin[i] = min(smin[i+1],arr[i]);
        }

        int ans = 1;
        for(int i=0;i<n-1;i++){
            if(pmax[i] <= smin[i+1]){
                ans++;
            }
        }

        return ans;
    }
};