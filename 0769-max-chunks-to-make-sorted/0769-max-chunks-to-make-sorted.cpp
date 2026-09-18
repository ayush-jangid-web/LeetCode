class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum == i*(i+1)/2){
                ans++;
            }
        }
        return ans;
    }
};