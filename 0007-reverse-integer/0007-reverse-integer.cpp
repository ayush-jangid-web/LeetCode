class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x!=0){
            int d = x%10;
            ans = ans*10 + d;
            if(INT_MIN > ans || ans > INT_MAX){
                return 0;
            }
            x/=10;
        }
        return ans;
    }
};