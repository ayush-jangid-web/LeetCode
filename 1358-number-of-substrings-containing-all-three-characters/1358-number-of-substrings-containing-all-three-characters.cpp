class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int i = 0;
        int j = 0;
        int cnt = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(i<n ){
            
            while((a==0 || b==0 || c==0)&& j<n){
                if(s[j] == 'a'){
                    a++;
                }
                if(s[j] == 'b'){
                    b++;
                }
                if(s[j] == 'c'){
                    c++;
                }
                j++;
            }

            if(a==0 || b==0 || c==0){
                break;
            }
            
            cnt += n-j+1;
            
            if(s[i] == 'a'){
                a--;
            }
            if(s[i] == 'b'){
                b--;
            }
            if(s[i] == 'c'){
                c--;
            }
            i++;
        }

        return cnt;
    }
};