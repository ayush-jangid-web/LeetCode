class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;

        int n = s.length();
        int m = t.length();

        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }

        for(int i=0;i<m;i++){
            mp[t[i]]--;
        }

        int ans = 0;
        for(auto &it:mp){
            ans+=abs(it.second);
        }
        return ans;
    }
};