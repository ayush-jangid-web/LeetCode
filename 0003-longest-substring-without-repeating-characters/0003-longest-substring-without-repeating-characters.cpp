class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;

        int i = 0;
        int cnt = 0;
        unordered_map<char,int>mp;
        for(int j=0;j<n;j++){
            char ch = s[j];
            mp[ch]++;
            cnt++;
            if(mp[ch]>1){
                while(mp[ch] > 1){
                    mp[s[i]]--;
                    cnt--;
                    i++;
                }
            }
            ans = max(cnt,ans);
        }

        return ans;
    }
};