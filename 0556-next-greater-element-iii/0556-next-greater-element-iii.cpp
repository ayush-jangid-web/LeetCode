class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int m = s.size();

        char pre = ' ';
        char next = ' ';
        int idx1 = -1;
        int k = -1;
        for(int i=m-2;i>=0;i--){
            pre = s[i+1];
            next  = s[i];
            if(next < pre){
                idx1 = i;
                k = s[i];
                break;
            }
        }

        if(idx1 == -1 || k == -1){
            return -1;
        }
        int idx2 = -1;
        for(int i = m-1;i>=0;i--){
            if(s[i] > k){
                idx2 = i;
                break;
            }
        }

        if(idx2 == -1){
            return -1; 
        }

        swap(s[idx1],s[idx2]);

        sort(s.begin()+idx1+1,s.end());

        long long ans = stoll(s);
        return (ans > INT_MAX) ? -1 : ans;
    }
};