class Solution {
public:
    int countAsterisks(string s) {
        
        int n = s.length();
        int flag = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '|'){
                flag ++;
            }
            if(flag%2 == 0){
                if(ch == '*'){
                    ans++;
                }
            }
        }
        return ans;
    }
};