class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int buy = INT_MAX;
        for(int i=0;i<n;i++){
            buy = min(buy,prices[i]);

            ans = max(ans,prices[i] - buy);
        }
        return ans;
    }
};