class Solution {
    bool check(string temp,unordered_map<char,int>& mp){
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
            string temp="";
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                temp+=s[j];
                mp[s[j]]++;
                if(check(temp,mp)){
                    int l = temp.length();
                    ans= max(ans,l);
                }
            }
        }
        return ans;
    }
};