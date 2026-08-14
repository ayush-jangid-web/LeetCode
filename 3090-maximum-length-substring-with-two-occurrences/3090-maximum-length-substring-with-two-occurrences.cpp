class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        int left=0;
        int right=0;
        int ans=0;
        while(right < n ){
            char ch = s[right];
            mp[ch]++;
            while(mp[ch]>2){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};