class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long sum = 0;
        int i = 0;
        while(n!=0){
            int digit = n%10;
            sum+=digit;
            if(digit!=0){
                ans = ans + digit*(pow(10,i++));
            }
            n /= 10;
        }
        return ans*sum;
    }
};