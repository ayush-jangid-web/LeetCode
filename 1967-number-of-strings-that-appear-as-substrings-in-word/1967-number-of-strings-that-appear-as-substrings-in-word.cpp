class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string,int> substring;
        int cnt = 0;
        int n = word.length();

        for(int i=0;i<n;i++){
            string s = "";
            for(int j = i;j<n;j++){
                s += word[j];
                substring[s]++;
            }
        }

        int a = patterns.size();
        for(int i = 0;i<a;i++){
            if(substring[patterns[i]] > 0){
                cnt++;
            }
        }

        
        return cnt;
    }
};