class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.length();
        int v = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i]) || s[i] == ' '){
                continue;
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                v++;
            }
            else{
                c++;
            }
        }

        if(c == 0){
            return 0;
        }
        
        return v/c;
    }
};