class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>mp;
        int n = paragraph.length();
        string word = ""; 
        for(int i=0;i<n;i++){
            char ch = tolower(paragraph[i]);
            if(ch == '!' || ch == '?' || ch == '\'' || ch == ',' || ch == ';' || ch == '.' || ch == ' '){
                if(word!=""){
                    mp[word]++;
                }
                word = "";
            }else{
                word += ch;
            }
        }

        if(!word.empty()){
            mp[word]++;
        }

        for(auto &it:banned){
            if(mp[it] > 0){
                mp[it] = 0;
            }
        }

        string ans = "";
        int maxi = 0;
        for(auto &it:mp){
            if(it.second > maxi ){
                ans = it.first;
                maxi = it.second;
            }
        }
        return ans;
    }
};