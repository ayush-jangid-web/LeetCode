class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;

        int n = s.length();
        int m = knowledge.size();

        for(int i=0;i<m;i++){
            string key = knowledge[i][0];
            string val = knowledge[i][1];

            mp[key] = val;
        }

        int i = 0;
        int j = 0;
        string ans = "";

        bool isbracket = false;
        string temp = "";
        while(i<n){
            char ch = s[i];

            if(ch == '('){
                isbracket = true;
            }

            if(ch == ')'){
                isbracket = false;
                if(mp.find(temp) == mp.end()){
                    ans += '?';
                }
                else{
                    ans += mp[temp];
                }
                temp = "";
            }

            if(isbracket == false && ch != '(' && ch != ')'){
                ans += ch;
            }
            if(isbracket == true && ch != '(' && ch != ')'){
                temp += ch;
            }
            i++;
        }
        return ans;
    }
};