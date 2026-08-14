class Solution {
    bool check(unordered_map<char,int>& mp){
        for(auto &it:mp){
            if(it.second > 2){
                return false;
            }
        }
        return true;
    }
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(check(mp)){
                    int l = j-i+1;
                    ans= max(ans,l);
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};