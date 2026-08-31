class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int,int>mp;
        int ans = INT_MAX;
        int cnt = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            mp[cards[j]]++;
            cnt++;

            while(mp[cards[j]] > 1){
                ans = min(ans,cnt);
                mp[cards[i]]--;
                cnt--;
                i++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};