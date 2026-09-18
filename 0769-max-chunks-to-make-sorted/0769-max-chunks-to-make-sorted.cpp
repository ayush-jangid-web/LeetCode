class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == i*(i+1)/2){
                ans++;
            }
        }
        return ans;
    }
};