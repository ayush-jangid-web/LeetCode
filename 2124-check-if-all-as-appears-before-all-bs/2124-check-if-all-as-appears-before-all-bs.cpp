class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int a = -1;
        int b = -1;
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                a = i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'b'){
                b = i;
            }
        }
        if(b == -1 || a == -1){
            return true;
        }
        if(b < a){
            return false;
        }
        return true;
    }
};