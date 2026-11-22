class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mp;
        int n = s.length();
        string temp = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
                mp[s[i]] = temp;
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        string ans = "";
        for(auto &it:mp){
            ans += it.second;
            ans += " ";
        }

        ans.pop_back();
        return ans;
    }
};