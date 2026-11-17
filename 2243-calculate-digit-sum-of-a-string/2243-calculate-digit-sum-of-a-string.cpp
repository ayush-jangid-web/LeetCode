class Solution {
    string solve(string s, int k, int n){
        if (k >= n) {
            return s;
        }
        string temp = "";
        for(int i=0;i<n;i=i+k){

            int sum = 0;
            for(int j=i;j<min(i+k,n);j++){
               sum += s[j] - '0';
            }
             temp+= to_string(sum);
        }

        return solve(temp,k,temp.length());
    }
    public:
        string digitSum(string s, int k) {
            int n = s.length();
            if (k >= n) {
                return s;
            }

            return solve(s, k, n);
        }
    };