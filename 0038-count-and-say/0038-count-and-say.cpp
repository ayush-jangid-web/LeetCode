class Solution {
    string solvecount(string s){
        int n = s.length();
        vector<vector<char>>mp;
        if(n == 0){
            return "";
        }

        int i=0;
        int j=0;
        while(i < n && j<n){
            vector<char>temp;
            while(j < n && s[i] == s[j]){
                temp.push_back(s[j]);
                j++;
            }
            mp.push_back(temp);
            i = j;
        }

        string result = "";
        for(auto &it:mp){
            int k = it.size();
            char val = ' ';
            if(k>0){
                val = it[0];
            }
            result += to_string(k);
            result += val;
        }
        return result;
    }
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i=1;i<n;i++){
            result = solvecount(result);
        }
        return result;
    }
};