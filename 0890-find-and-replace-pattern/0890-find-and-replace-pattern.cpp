class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int n = pattern.length();

        for(auto &it:words){
            string t = it;

            unordered_map<char,char>mp1;
            unordered_map<char,char>mp2;

            int i=0;
            bool valid = true;
            while(i<n){
                char ch1 = t[i];
                char ch2 = pattern[i];
                
                if(mp1.count(ch1) != 0 && mp1[ch1] != ch2){
                    valid = false;
                    break;
                }
                if(mp2.count(ch2) != 0 && mp2[ch2] != ch1){
                    valid = false;
                    break;
                }
                    mp1[ch1] = ch2;
                    mp2[ch2] = ch1;
                    i++;
            }
            if(valid == false){
                continue;
            }
            else{
                ans.push_back(t);
            }
        }
        return ans;
    }
};