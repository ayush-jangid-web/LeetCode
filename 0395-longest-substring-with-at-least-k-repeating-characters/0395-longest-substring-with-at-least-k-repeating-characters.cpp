class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ans = 0;

        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                bool valid = true;
                
                for(auto &it:mp){
                    if(it.second > 0 && it.second < k){
                        valid = false;
                        break;
                    }
                }

                if(valid){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};