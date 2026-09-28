class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        if(n == 1){
            return 0;
        }
        int result = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                ans++;
            }
            else if(s[i] == ')'){
                ans--;
            }
            else{
                continue;
            }
            result = max(ans,result);
        }
        return result;
    }
};